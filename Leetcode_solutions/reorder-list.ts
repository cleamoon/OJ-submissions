function reorderList(head: ListNode | null): void {
    const arr = []

    let curr = head

    while (curr) {
        arr.push({ val: curr.val, next: curr.next })
        curr = curr.next
    }

    const len = arr.length
    let i = 0
    curr = head
    while ((i + 1) * 2 < len) {
        const next = curr.next
        curr.next = arr[len - i - 1]
        curr.next.next = next
        curr = next
        i += 1
    }
    if (len % 2 === 1) {
        curr.next = null
    } else {
        curr.next.next = null
    }
};