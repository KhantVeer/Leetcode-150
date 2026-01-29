"""
Number of Islands
Count islands of '1's in a 2D grid using DFS.
"""
from typing import List

def num_islands(grid: List[List[str]]) -> int:
    if not grid: return 0
    m, n = len(grid), len(grid[0])
    def dfs(i,j):
        if i<0 or j<0 or i>=m or j>=n or grid[i][j] != '1': return
        grid[i][j] = '0'
        dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i,j-1)
    cnt = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == '1':
                cnt += 1
                dfs(i,j)
    return cnt

if __name__ == '__main__':
    g = [['1','1','0','0','0'],['1','1','0','0','0'],['0','0','1','0','0'],['0','0','0','1','1']]
    print('Number of islands:', num_islands(g))

# Time Complexity: O(m*n)
# Space Complexity: O(m*n)
