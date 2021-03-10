#include <unordered_map>

using namespace std;

struct Node {
  int val;
  Node *next, *random;
  explicit Node(int val_) : val{val_}, next{nullptr}, random{nullptr} {}
};

class Solution {
 private:
  Node *copyList(Node *head, unordered_map<Node *, Node *> *loc) {
    Node *node = nullptr, *last = nullptr;
    while (head != nullptr) {
      Node *cur = new Node{head->val};
      loc->insert({head, cur});
      if (node == nullptr) {
        node = cur;
      } else {
        last->next = cur;
      }
      last = cur;
      head = head->next;
    }
    return node;
  }

 public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr) {
      return nullptr;
    }
    unordered_map<Node *, Node *> loc;
    Node *clone = copyList(head, &loc);

    for (Node *dest = clone, *src = head; dest != nullptr;
         src = src->next, dest = dest->next) {
      if (src->random != nullptr) {
        dest->random = loc.find(src->random)->second;
      }
    }
    return clone;
  }
};
