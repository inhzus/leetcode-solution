#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  string multiply(string lhs, string rhs) {
    if (lhs.size() < rhs.size()) {
      lhs.swap(rhs);
    }

    std::vector<string> internal{};
    internal.reserve(rhs.size());
    int max_length = 0;
    for (int i = rhs.size() - 1; i >= 0; --i) {
      int carry = 0;
      string cur{};
      cur.reserve(lhs.size() + rhs.size() - i);
      cur.assign(rhs.size() - 1 - i, '0');
      for (int j = lhs.size() - 1; j >= 0; --j) {
        int val = (rhs[i] - '0') * (lhs[j] - '0') + carry;
        carry = val / 10;
        val %= 10;
        cur.push_back('0' + val);
      }
      if (carry != 0) {
        cur.push_back('0' + carry);
      }
      max_length = max(max_length, static_cast<int>(cur.size()));
      internal.push_back(std::move(cur));
    }
    string &result = internal.at(0);
    for (int i = 1; i < internal.size(); ++i) {
      string &src = internal.at(i);
      result.resize(src.size(), '0');
      src.resize(result.size(), '0');
      int carry = 0;
      for (int j = 0; j < src.size(); ++j) {
        int val = (result[j] - '0') + (src[j] - '0') + carry;
        carry = val / 10;
        result[j] = '0' + val % 10;
      }
      if (carry != 0) {
        result.push_back('0' + carry);
      }
    }
    while (result.size() > 1 && result.back() == '0') {
      result.pop_back();
    }
    for (int i = 0; i < result.size() / 2; ++i) {
      swap(result[i], result[result.size() - 1 - i]);
    }
    return result;
  }
};
