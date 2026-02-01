/*
142. Triangle
Find minimum path sum from top to bottom of a triangle. Use bottom-up DP to reuse space.
*/
#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(triangle.back());
    for (int layer = n-2; layer >= 0; --layer) {
        for (int i = 0; i <= layer; ++i) dp[i] = triangle[layer][i] + min(dp[i], dp[i+1]);
    }
    return dp[0];
}

int main() {
    vector<vector<int>> tri{{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << "minimumTotal = " << minimumTotal(tri) << "\n"; // 11
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
