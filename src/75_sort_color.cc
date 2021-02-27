#include <cstdio>
#include <memory>
#include <vector>
using namespace std;

class Solution {
 public:
  void sortColors(vector<int>& nums) {
    std::array<size_t, 3> cnts{0, 0, 0};
    for (auto item : nums) {
      ++cnts[item];
    }
    size_t cur = 0;
    for (int i = 0; i < 3; ++i) {
      std::fill(nums.begin() + cur, nums.begin() + cur + cnts[i], i);
      cur += cnts[i];
    }
  }
};
