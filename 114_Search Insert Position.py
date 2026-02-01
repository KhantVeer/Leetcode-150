"""
114. Search Insert Position
Return the index of target in a sorted array or the insertion position if not found.
Binary search, O(log n) time.
"""
from typing import List

def search_insert(nums: List[int], target: int) -> int:
    l, r = 0, len(nums) - 1
    while l <= r:
        m = (l + r) // 2
        if nums[m] == target:
            return m
        if nums[m] < target:
            l = m + 1
        else:
            r = m - 1
    return l

if __name__ == '__main__':
    a = [1,3,5,6]
    print('searchInsert([1,3,5,6],5) =', search_insert(a,5))  # 2
    print('searchInsert([1,3,5,6],2) =', search_insert(a,2))  # 1
    print('searchInsert([1,3,5,6],7) =', search_insert(a,7))  # 4

# Time Complexity: O(log n)
# Space Complexity: O(1)
