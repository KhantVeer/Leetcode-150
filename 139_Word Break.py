"""
139. Word Break
Dynamic programming to check if s can be segmented using words in dict.
"""
from typing import List

def word_break(s: str, wordDict: List[str]) -> bool:
    dict_set = set(wordDict)
    n = len(s)
    dp = [False] * (n+1)
    dp[0] = True
    for i in range(1, n+1):
        for j in range(i):
            if dp[j] and s[j:i] in dict_set:
                dp[i] = True
                break
    return dp[n]

if __name__ == '__main__':
    print("wordBreak('leetcode') =", word_break('leetcode', ['leet','code']))
    print("wordBreak('applepenapple') =", word_break('applepenapple', ['apple','pen']))

# Time Complexity: O(n^2 * k) where k is substring check cost
# Space Complexity: O(n)
