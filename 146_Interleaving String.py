"""
146. Interleaving String
DP table where dp[i][j] indicates s3[:i+j] can be formed from s1[:i] and s2[:j].
"""
from typing import List

def is_interleave(s1: str, s2: str, s3: str) -> bool:
    n1, n2 = len(s1), len(s2)
    if n1 + n2 != len(s3): return False
    dp = [[False] * (n2+1) for _ in range(n1+1)]
    dp[0][0] = True
    for i in range(n1+1):
        for j in range(n2+1):
            if i > 0 and dp[i-1][j] and s1[i-1] == s3[i+j-1]: dp[i][j] = True
            if j > 0 and dp[i][j-1] and s2[j-1] == s3[i+j-1]: dp[i][j] = True
    return dp[n1][n2]

if __name__ == '__main__':
    print(is_interleave('aab','axy','aaxaby'))
    print(is_interleave('aab','abc','aaabcb'))

# Time Complexity: O(n1*n2)
# Space Complexity: O(n1*n2)
