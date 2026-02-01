"""
142. Triangle
Bottom-up DP collapsing rows to compute min path sum.
"""
from typing import List

def minimum_total(triangle: List[List[int]]) -> int:
    dp = triangle[-1][:]
    for layer in range(len(triangle)-2, -1, -1):
        for i in range(layer+1):
            dp[i] = triangle[layer][i] + min(dp[i], dp[i+1])
    return dp[0]

if __name__ == '__main__':
    print('minimumTotal =', minimum_total([[2],[3,4],[6,5,7],[4,1,8,3]]))

# Time Complexity: O(n^2)
# Space Complexity: O(n)
