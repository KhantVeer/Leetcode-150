"""
128. Single Number
Every element appears twice except for one. Find the single one using XOR.
"""
from typing import List

def single_number(nums: List[int]) -> int:
    x = 0
    for v in nums:
        x ^= v
    return x

if __name__ == '__main__':
    print('singleNumber([2,2,1]) =', single_number([2,2,1]))  # 1
    print('singleNumber([4,1,2,1,2]) =', single_number([4,1,2,1,2]))  # 4

# Time Complexity: O(n)
# Space Complexity: O(1)
