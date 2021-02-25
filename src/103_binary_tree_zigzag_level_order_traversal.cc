#include <cstdio>
#include <list>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
  void traverse(TreeNode *cur, int depth, vector<list<int>> *v) {
    if (cur == nullptr) {
      return;
    }

    if (depth >= v->size()) {
      v->emplace_back(1, cur->val);
    } else {
      if (depth % 2 == 0) {
        v->at(depth).push_back(cur->val);
      } else {
        v->at(depth).push_front(cur->val);
      }
    }
    traverse(cur->left, depth + 1, v);
    traverse(cur->right, depth + 1, v);
  }

 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<list<int>> v{};
    traverse(root, 0, &v);
    vector<vector<int>> res{};
    res.reserve(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
      res.emplace_back(v[i].begin(), v[i].end());
    }
    return res;
  }
};
