"""
Combinations
Return all combinations of k numbers chosen from 1..n.
"""
from typing import List

def combine(n: int, k: int) -> List[List[int]]:
    res = []
    def dfs(start, cur):
        if len(cur) == k:
            res.append(cur.copy()); return
        for i in range(start, n+1):
            cur.append(i); dfs(i+1, cur); cur.pop()
    dfs(1, [])
    return res

if __name__ == '__main__':
    print('Combinations:', combine(4,2))

# Time Complexity: O(C(n,k) * k)
# Space Complexity: O(k)
