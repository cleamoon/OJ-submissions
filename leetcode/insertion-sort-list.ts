/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function insertionSortList(head: ListNode | null): ListNode | null {
    let first = new ListNode(head.val)
    let curr = head.next
    let next = null
    while(curr) {
        next = curr.next
        if (curr.val <= first.val) {
            curr.next = first
            first = curr
        } else {
            let loc = first
            while(loc.next && loc.next.val < curr.val) {
                loc = loc.next
            }
            curr.next = loc.next
            loc.next = curr
        }
        curr = next
    }
    return first
};
