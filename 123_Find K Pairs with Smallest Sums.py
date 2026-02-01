"""
123. Find K Pairs with Smallest Sums
Return k pairs with smallest sums using a min-heap seeded from nums1.
"""
from typing import List, Tuple
import heapq

def k_smallest_pairs(nums1: List[int], nums2: List[int], k: int) -> List[Tuple[int,int]]:
    res = []
    if not nums1 or not nums2 or k <= 0:
        return res
    n1, n2 = len(nums1), len(nums2)
    pq = []  # (sum, i, j)
    for i in range(min(n1, k)):
        heapq.heappush(pq, (nums1[i] + nums2[0], i, 0))
    while pq and len(res) < k:
        s, i, j = heapq.heappop(pq)
        res.append((nums1[i], nums2[j]))
        if j + 1 < n2:
            heapq.heappush(pq, (nums1[i] + nums2[j+1], i, j+1))
    return res

if __name__ == '__main__':
    print('kSmallestPairs([1,7,11],[2,4,6],3) =', k_smallest_pairs([1,7,11],[2,4,6],3))
    print('kSmallestPairs([1,1,2],[1,2,3],2) =', k_smallest_pairs([1,1,2],[1,2,3],2))

# Time Complexity: O(k log min(n1,k))
# Space Complexity: O(min(n1,k))
