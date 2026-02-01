"""
112. Maximum Subarray
Find the contiguous subarray with the largest sum (Kadane's algorithm).
"""
from typing import List

def max_subarray(nums: List[int]) -> int:
    best = nums[0]
    cur = nums[0]
    for x in nums[1:]:
        cur = max(x, cur + x)
        best = max(best, cur)
    return best

if __name__ == '__main__':
    print('MaxSubArray([-2,1,-3,4,-1,2,1,-5,4]) =', max_subarray([-2,1,-3,4,-1,2,1,-5,4]))  # 6
    print('MaxSubArray([1]) =', max_subarray([1]))  # 1
    print('MaxSubArray([-1,-2,-3]) =', max_subarray([-1,-2,-3]))  # -1

# Time Complexity: O(n)
# Space Complexity: O(1)
