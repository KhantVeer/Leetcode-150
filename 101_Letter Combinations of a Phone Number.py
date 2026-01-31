"""
Letter Combinations of a Phone Number
Return all possible letter combinations a phone number could represent.
"""
from typing import List

def letter_combinations(digits: str) -> List[str]:
    if not digits: return []
    mapping = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
    res = []
    def dfs(i, cur):
        if i == len(digits):
            res.append(''.join(cur))
            return
        for c in mapping[ord(digits[i]) - ord('0')]:
            cur.append(c)
            dfs(i+1, cur)
            cur.pop()
    dfs(0, [])
    return res

if __name__ == '__main__':
    print('Combinations:', letter_combinations('23'))

# Time Complexity: O(4^n)
# Space Complexity: O(n) recursion + output
