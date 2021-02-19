#include <cstdio>
#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int low, int high, int target) {
    if (low == high) {
      return target == nums.at(low) ? low : -1;
    }

    if (nums.at(low) < nums.at(high)) {
      if (target < nums.at(low) || target > nums.at(high)) {
        return -1;
      }
    } else { // nums.at(low) > nums.at(high)
      if (target < nums.at(low) && target > nums.at(high)) {
        return -1;
      }
    }

    int lhs = (low + high) / 2;
    int rhs = lhs + 1;
    int res = search(nums, low, lhs, target);
    if (res != -1) {
      return res;
    }

    return search(nums, rhs, high, target);
  }
  int search(std::vector<int> &nums, int target) {
    return search(nums, 0, nums.size() - 1, target);
  }
};

int main() {
  Solution s{};
  std::vector<std::vector<int>> vs{
      {4, 5, 6, 7, 0, 1, 2}, {4, 5, 6, 7, 0, 1, 2}, {1}};
  std::vector<int> target{0, 3, 0};
  for (size_t i = 0; i < vs.size(); ++i) {
    printf("%d\n", s.search(vs.at(i), target.at(i)));
  }

  return 0;
}
