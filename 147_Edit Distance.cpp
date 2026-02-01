/*
147. Edit Distance
Compute min operations (insert/delete/replace) to convert word1 -> word2 using DP.
*/
#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[m][n];
}

int main() {
    cout << "minDistance('horse','ros') = " << minDistance("horse","ros") << "\n"; // 3
    cout << "minDistance('intention','execution') = " << minDistance("intention","execution") << "\n"; // 5
    return 0;
}

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
