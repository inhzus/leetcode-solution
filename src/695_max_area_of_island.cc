#include <bitset>
#include <vector>
using namespace std;

class Solution {
 public:
  struct Desc {
    vector<vector<int>> &grid;
    const size_t row;
    const size_t column;
  };

 private:
  int islandArea(size_t i, size_t j, Desc *desc) {
    if (desc->grid.at(i).at(j) == 0) {
      return 0;
    }

    desc->grid.at(i).at(j) = 0;
    int cnt = 1;
    if (i >= 1) {
      cnt += islandArea(i - 1, j, desc);
    }
    if (i + 1 < desc->row) {
      cnt += islandArea(i + 1, j, desc);
    }
    if (j >= 1) {
      cnt += islandArea(i, j - 1, desc);
    }
    if (j + 1 < desc->column) {
      cnt += islandArea(i, j + 1, desc);
    }
    return cnt;
  }

 public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    if (grid.empty() || grid.at(0).empty()) {
      return 0;
    }
    int cnt = 0;
    Desc desc{grid, grid.size(), grid.at(0).size()};
    for (size_t i = 0; i < desc.row; ++i) {
      for (size_t j = 0; j < desc.column; ++j) {
        cnt = std::max(cnt, islandArea(i, j, &desc));
      }
    }
    return cnt;
  }
};

int main() {
  vector<vector<int>> grid{
      {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
  Solution{}.maxAreaOfIsland(grid);
  return 0;
}
