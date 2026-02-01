/*
143. Minimum Path Sum
Given a grid, find min path sum from top-left to bottom-right (only right and down moves).
Use in-place DP or separate dp array.
*/
#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) dp[j] = dp[j] + grid[i][j];
            else dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
        }
    }
    return dp[n-1];
}

int main() {
    vector<vector<int>> g{{1,3,1},{1,5,1},{4,2,1}};
    cout << "minPathSum = " << minPathSum(g) << "\n"; // 7
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(n)
