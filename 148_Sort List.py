"""
148. Sort List
Sort a singly-linked list in O(n log n) time using merge sort.
"""
from typing import Optional, List

class ListNode:
    def __init__(self, x: int):
        self.val = x
        self.next = None

def mergeTwo(l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(0)
    p = dummy
    while l1 and l2:
        if l1.val < l2.val:
            p.next = l1; l1 = l1.next
        else:
            p.next = l2; l2 = l2.next
        p = p.next
    p.next = l1 or l2
    return dummy.next

def sortList(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next:
        return head
    slow, fast, prev = head, head, None
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
    prev.next = None
    l1 = sortList(head)
    l2 = sortList(slow)
    return mergeTwo(l1, l2)

def make_list(a: List[int]) -> Optional[ListNode]:
    dummy = ListNode(0)
    p = dummy
    for x in a:
        p.next = ListNode(x); p = p.next
    return dummy.next

def print_list(head: Optional[ListNode]):
    p = head
    out = []
    while p:
        out.append(str(p.val)); p = p.next
    print(" -> ".join(out))

if __name__ == '__main__':
    l1 = make_list([4,2,1,3])
    print('Original:', end=' '); print_list(l1)
    s1 = sortList(l1)
    print('Sorted:', end=' '); print_list(s1)

    l2 = make_list([-1,5,3,4,0])
    print('Original:', end=' '); print_list(l2)
    s2 = sortList(l2)
    print('Sorted:', end=' '); print_list(s2)

# Time Complexity: O(n log n)
# Space Complexity: O(log n) recursion stack
