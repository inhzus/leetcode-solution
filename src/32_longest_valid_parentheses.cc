#include <algorithm>
#include <cstdio>
#include <stack>
#include <string>

class Solution {
public:
  int longestValidParentheses(std::string s) {
    int max = 0;
    std::stack<int> stack{};
    stack.push(-1);
    for (size_t i = 0; i < s.size(); ++i) {
      char ch = s[i];
      if (ch == ')') {
        stack.pop();
        if (stack.empty()) {
          stack.push(i);
        } else {
          int cur = std::max(max, int(i - stack.top()));
          max = std::max(max, cur);
        }
      } else if (ch == '(') {
        stack.push(i);
      }
    }
    return max;
  }
};

int main() {
  Solution s{};
  printf("%d\n", s.longestValidParentheses(")()())"));
  printf("%d\n", s.longestValidParentheses("(()"));
  printf("%d\n", s.longestValidParentheses("()(()"));
  return 0;
}
