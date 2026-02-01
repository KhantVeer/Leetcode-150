/*
144. Unique Paths II
Number of unique paths in grid with obstacles (1 = obstacle). Use DP in-place or 1D array.
*/
#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n,0);
    dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[i][j] == 1) dp[j] = 0;
            else if (j > 0) dp[j] += dp[j-1];
        }
    }
    return dp[n-1];
}

int main() {
    vector<vector<int>> g{{0,0,0},{0,1,0},{0,0,0}};
    cout << "uniquePathsWithObstacles = " << uniquePathsWithObstacles(g) << "\n"; // 2
    vector<vector<int>> g2{{0,1},{0,0}};
    cout << "uniquePathsWithObstacles = " << uniquePathsWithObstacles(g2) << "\n"; // 1
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(n)
