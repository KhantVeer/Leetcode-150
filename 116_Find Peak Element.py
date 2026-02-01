"""
116. Find Peak Element
Use binary search to locate any peak (nums[i] != nums[i+1]).
"""
from typing import List

def find_peak_element(nums: List[int]) -> int:
    l, r = 0, len(nums) - 1
    while l < r:
        m = (l + r) // 2
        if nums[m] > nums[m+1]:
            r = m
        else:
            l = m + 1
    return l

if __name__ == '__main__':
    print('findPeakElement([1,2,3,1]) =', find_peak_element([1,2,3,1]))
    print('findPeakElement([1,2,1,3,5,6,4]) =', find_peak_element([1,2,1,3,5,6,4]))

# Time Complexity: O(log n)
# Space Complexity: O(1)
