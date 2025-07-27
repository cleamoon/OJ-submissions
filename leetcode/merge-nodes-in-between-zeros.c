/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
  struct ListNode* curr = head;
  while (true) {
      if (curr == NULL) return head;
      if (curr->next->val == 0) {
          curr->next = curr->next->next;
          curr = curr->next;
      } else {
          curr->val += curr->next->val;
          curr->next = curr->next->next;
      }
  }
  return head;
}