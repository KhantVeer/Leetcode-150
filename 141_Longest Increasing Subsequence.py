"""
141. Longest Increasing Subsequence
Use patience sorting (tails array + bisect) to get O(n log n).
"""
from bisect import bisect_left
from typing import List

def length_of_lis(nums: List[int]) -> int:
    tails = []
    for x in nums:
        i = bisect_left(tails, x)
        if i == len(tails):
            tails.append(x)
        else:
            tails[i] = x
    return len(tails)

if __name__ == '__main__':
    print('LIS length =', length_of_lis([10,9,2,5,3,7,101,18]))
    print('LIS length =', length_of_lis([0,1,0,3,2,3]))

# Time Complexity: O(n log n)
# Space Complexity: O(n)
