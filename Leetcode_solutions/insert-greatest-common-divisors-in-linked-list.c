/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

struct ListNode *insertGreatestCommonDivisors(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = slow->next;

    while (fast != NULL)
    {
        int gcd_val = gcd(slow->val, fast->val);
        struct ListNode *new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = gcd_val;
        new_node->next = fast;
        slow->next = new_node;
        slow = fast;
        fast = fast->next;
    }

    return head;
}