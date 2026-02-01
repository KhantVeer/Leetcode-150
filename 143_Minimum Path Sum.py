"""
143. Minimum Path Sum
DP across rows keeping rolling 1D array.
"""
from typing import List

def min_path_sum(grid: List[List[int]]) -> int:
    m, n = len(grid), len(grid[0])
    dp = [float('inf')] * n
    dp[0] = 0
    for i in range(m):
        for j in range(n):
            if j == 0:
                dp[j] = dp[j] + grid[i][j]
            else:
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j]
    return dp[-1]

if __name__ == '__main__':
    print('minPathSum =', min_path_sum([[1,3,1],[1,5,1],[4,2,1]]))

# Time Complexity: O(m*n)
# Space Complexity: O(n)
