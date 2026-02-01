"""
Sort List
Sort a linked list in O(n log n) time using merge sort on linked lists.
"""
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def merge(a: Optional[ListNode], b: Optional[ListNode]) -> Optional[ListNode]:
    dummy = ListNode(0); p = dummy
    while a and b:
        if a.val < b.val:
            p.next = a; a = a.next
        else:
            p.next = b; b = b.next
        p = p.next
    p.next = a or b
    return dummy.next

def sort_list(head: Optional[ListNode]) -> Optional[ListNode]:
    if not head or not head.next: return head
    slow, fast = head, head.next
    while fast and fast.next:
        slow = slow.next; fast = fast.next.next
    mid = slow.next; slow.next = None
    left = sort_list(head); right = sort_list(mid)
    return merge(left, right)

if __name__ == '__main__':
    a = ListNode(4, ListNode(2, ListNode(1, ListNode(3))))
    s = sort_list(a)
    vals = []
    while s:
        vals.append(s.val); s = s.next
    print('Sorted list:', vals)

# Time Complexity: O(n log n)
# Space Complexity: O(log n)
