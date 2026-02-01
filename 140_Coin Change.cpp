/*
140. Coin Change
Given coin denominations and amount, find the fewest coins needed to make up that amount (unbounded knapsack / DP).
Return -1 if not possible.
*/
#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    const int INF = 1e9;
    vector<int> dp(amount+1, INF);
    dp[0] = 0;
    for (int c : coins) {
        for (int a = c; a <= amount; ++a) dp[a] = min(dp[a], dp[a-c] + 1);
    }
    return dp[amount] == INF ? -1 : dp[amount];
}

int main() {
    vector<int> coins{1,2,5};
    cout << "coinChange([1,2,5],11) = " << coinChange(coins, 11) << "\n"; // 3
    vector<int> coins2{2};
    cout << "coinChange([2],3) = " << coinChange(coins2, 3) << "\n"; // -1
    return 0;
}

// Time Complexity: O(amount * n_coins)
// Space Complexity: O(amount)
