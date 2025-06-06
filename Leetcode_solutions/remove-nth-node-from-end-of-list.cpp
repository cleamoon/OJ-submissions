/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = new ListNode(0, head);
        ListNode* fast = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == nullptr) {
            return slow->next->next;
        }
        while(true) {
            if (fast == nullptr) {
                slow -> next = slow -> next -> next;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return head;
    }
};
