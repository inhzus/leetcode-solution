struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 private:
  ListNode *reverse(ListNode *node) {
    if (node == nullptr || node->next == nullptr) {
      return node;
    }

    ListNode *prev = nullptr, *cur = node;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }

 public:
  ListNode *addTwoNumbers(ListNode *lhs, ListNode *rhs) {
    lhs = reverse(lhs);
    rhs = reverse(rhs);
    ListNode *last = nullptr;
    int carry = 0;
    while (lhs != nullptr || rhs != nullptr) {
      if (lhs != nullptr) {
        carry += lhs->val;
        lhs = lhs->next;
      }
      if (rhs != nullptr) {
        carry += rhs->val;
        rhs = rhs->next;
      }
      ListNode *cur = new ListNode(carry % 10, last);
      last = cur;
      carry = carry / 10;
    }
    if (carry != 0) {
      ListNode *cur = new ListNode(carry, last);
      last = cur;
    }
    return last;
  }
};
