"""
Merge k Sorted Lists
Merge k sorted linked lists using a heap (priority queue).
"""
from typing import List, Optional
import heapq

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __lt__(self, other):
        return self.val < other.val

def merge_k_lists(lists: List[Optional[ListNode]]) -> Optional[ListNode]:
    heap = [ln for ln in lists if ln]
    heapq.heapify(heap)
    dummy = ListNode(0); tail = dummy
    while heap:
        node = heapq.heappop(heap)
        tail.next = node; tail = tail.next
        if node.next: heapq.heappush(heap, node.next)
    return dummy.next

if __name__ == '__main__':
    a = ListNode(1, ListNode(4, ListNode(5)))
    b = ListNode(1, ListNode(3, ListNode(4)))
    c = ListNode(2, ListNode(6))
    res = merge_k_lists([a,b,c])
    vals = []
    while res: vals.append(res.val); res = res.next
    print('Merged:', vals)

# Time Complexity: O(N log k)
# Space Complexity: O(k)
