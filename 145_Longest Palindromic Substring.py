"""
145. Longest Palindromic Substring
Expand around each center (odd and even) to find longest palindrome.
"""
from typing import Tuple

def longest_palindrome(s: str) -> str:
    n = len(s)
    if n < 2: return s
    start, maxlen = 0, 1
    for i in range(n):
        # odd
        l, r = i, i
        while l >= 0 and r < n and s[l] == s[r]:
            if r - l + 1 > maxlen:
                start, maxlen = l, r - l + 1
            l -= 1; r += 1
        # even
        l, r = i, i+1
        while l >= 0 and r < n and s[l] == s[r]:
            if r - l + 1 > maxlen:
                start, maxlen = l, r - l + 1
            l -= 1; r += 1
    return s[start:start+maxlen]

if __name__ == '__main__':
    print(longest_palindrome('babad'))
    print(longest_palindrome('cbbd'))

# Time Complexity: O(n^2)
# Space Complexity: O(1)
