"""
144. Unique Paths II
DP with obstacles using 1D rolling array.
"""
from typing import List

def unique_paths_with_obstacles(obstacleGrid: List[List[int]]) -> int:
    m, n = len(obstacleGrid), len(obstacleGrid[0])
    dp = [0] * n
    dp[0] = 1 if obstacleGrid[0][0] == 0 else 0
    for i in range(m):
        for j in range(n):
            if obstacleGrid[i][j] == 1:
                dp[j] = 0
            elif j > 0:
                dp[j] += dp[j-1]
    return dp[-1]

if __name__ == '__main__':
    print('uniquePathsWithObstacles =', unique_paths_with_obstacles([[0,0,0],[0,1,0],[0,0,0]]))
    print('uniquePathsWithObstacles =', unique_paths_with_obstacles([[0,1],[0,0]]))

# Time Complexity: O(m*n)
# Space Complexity: O(n)
