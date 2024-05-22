class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        int len = 0;
        ListNode* curr = head;
        vector<ListNode*> list;
        while(curr != nullptr) {
            len++;
            list.push_back(curr);
            curr = curr->next;
        }
        int rot = k % len;
        if (rot == 0) return head;
        list[list.size() - 1]->next = head;
        list[list.size() - 1 - rot]->next = nullptr;
        return list[list.size() - rot];
    }
};