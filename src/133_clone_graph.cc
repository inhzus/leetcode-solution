#include <unordered_map>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 private:
  Node *traverse(Node *src, unordered_map<Node *, Node *> *flag) {
    if (src == nullptr) {
      return nullptr;
    }

    auto it = flag->find(src);
    if (it != flag->end()) {
      return it->second;
    }

    Node *node = new Node{src->val};
    node->neighbors.reserve(src->neighbors.size());
    flag->insert(make_pair(src, node));
    for (auto *link : src->neighbors) {
      node->neighbors.push_back(traverse(link, flag));
    }
    return node;
  }

 public:
  Node *cloneGraph(Node *node) {
    unordered_map<Node *, Node *> flag{};
    return traverse(node, &flag);
  }
};
