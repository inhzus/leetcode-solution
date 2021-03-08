#include <string>
#include <stack>

using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    string stack{};
    for (auto ch : num) {
      while (!stack.empty() && k > 0 && stack.back() > ch) {
        stack.pop_back();
        --k;
      }
      stack.push_back(ch);
    }
    
    for (int i = 0; i < k; ++i) {
      stack.pop_back();
    }

    auto non_zero = stack.find_first_not_of('0');
    if (non_zero == string::npos) {
      return "0";
    }

    return stack.substr(non_zero);
  }
};
