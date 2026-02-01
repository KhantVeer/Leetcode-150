"""
138. House Robber
DP solution: at each step choose max(rob current + prev2, prev1).
"""
from typing import List

def rob(nums: List[int]) -> int:
    n = len(nums)
    if n == 0: return 0
    if n == 1: return nums[0]
    prev2, prev1 = nums[0], max(nums[0], nums[1])
    for i in range(2, n):
        cur = max(prev1, prev2 + nums[i])
        prev2, prev1 = prev1, cur
    return prev1

if __name__ == '__main__':
    print('rob([1,2,3,1]) =', rob([1,2,3,1]))
    print('rob([2,7,9,3,1]) =', rob([2,7,9,3,1]))

# Time Complexity: O(n)
# Space Complexity: O(1)
