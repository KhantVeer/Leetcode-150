"""
118. Find First and Last Position of Element in Sorted Array
Use binary search to locate leftmost and rightmost indices of target.
"""
from typing import List

def left_bound(nums: List[int], target: int) -> int:
    l, r = 0, len(nums) - 1
    ans = -1
    while l <= r:
        m = (l + r) // 2
        if nums[m] >= target:
            if nums[m] == target: ans = m
            r = m - 1
        else:
            l = m + 1
    return ans

def right_bound(nums: List[int], target: int) -> int:
    l, r = 0, len(nums) - 1
    ans = -1
    while l <= r:
        m = (l + r) // 2
        if nums[m] <= target:
            if nums[m] == target: ans = m
            l = m + 1
        else:
            r = m - 1
    return ans

def search_range(nums: List[int], target: int) -> List[int]:
    return [left_bound(nums, target), right_bound(nums, target)]

if __name__ == '__main__':
    a = [5,7,7,8,8,10]
    print('searchRange([5,7,7,8,8,10],8) =', search_range(a,8))
    print('searchRange(...,6) =', search_range(a,6))
    print('searchRange([],0) =', search_range([],0))

# Time Complexity: O(log n)
# Space Complexity: O(1)
