"""
129. Single Number II
Every element appears three times except for one. Use bit counting per bit and mod 3.
Handles negative numbers by reconstructing two's complement.
"""
from typing import List

def single_number_ii(nums: List[int]) -> int:
    res = 0
    for i in range(32):
        s = 0
        for n in nums:
            s += (n >> i) & 1
        if s % 3:
            res |= (1 << i)
    # convert to signed
    if res >= 2**31:
        res -= 2**32
    return res

if __name__ == '__main__':
    print('singleNumberII([2,2,3,2]) =', single_number_ii([2,2,3,2]))  # 3
    print('singleNumberII([0,1,0,1,0,1,99]) =', single_number_ii([0,1,0,1,0,1,99]))  # 99

# Time Complexity: O(32*n) = O(n)
# Space Complexity: O(1)
