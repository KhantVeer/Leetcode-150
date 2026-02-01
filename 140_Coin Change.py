"""
140. Coin Change
Use DP to find the fewest coins to make amount (unbounded knapsack).
"""
from typing import List

def coin_change(coins: List[int], amount: int) -> int:
    INF = 10**9
    dp = [0] + [INF] * amount
    for c in coins:
        for a in range(c, amount+1):
            dp[a] = min(dp[a], dp[a-c] + 1)
    return -1 if dp[amount] == INF else dp[amount]

if __name__ == '__main__':
    print('coinChange([1,2,5],11) =', coin_change([1,2,5],11))
    print('coinChange([2],3) =', coin_change([2],3))

# Time Complexity: O(amount * n_coins)
# Space Complexity: O(amount)
