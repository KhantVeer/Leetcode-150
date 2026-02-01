"""
121. Kth Largest Element in an Array
Find the k-th largest element in an unsorted array. Use heapq.nlargest for simplicity.
"""
from typing import List
import heapq

def find_kth_largest(nums: List[int], k: int) -> int:
    # heapq.nlargest returns k largest elements in descending order
    return heapq.nlargest(k, nums)[-1]

if __name__ == '__main__':
    print('kthLargest([3,2,1,5,6,4],2) =', find_kth_largest([3,2,1,5,6,4],2))  # 5
    print('kthLargest([3,2,3,1,2,4,5,5,6],4) =', find_kth_largest([3,2,3,1,2,4,5,5,6],4))  # 4
    print('kthLargest([1],1) =', find_kth_largest([1],1))  # 1

# Time Complexity: O(n log k) or O(n) depending on implementation
# Space Complexity: O(k)
