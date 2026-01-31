"""
Combination Sum
Find all unique combinations of candidates that sum to target (reuse allowed).
"""
from typing import List

def combination_sum(candidates: List[int], target: int) -> List[List[int]]:
    candidates.sort()
    res = []
    def dfs(idx, cur, remain):
        if remain == 0:
            res.append(cur.copy()); return
        for i in range(idx, len(candidates)):
            if candidates[i] > remain: break
            cur.append(candidates[i])
            dfs(i, cur, remain - candidates[i])
            cur.pop()
    dfs(0, [], target)
    return res

if __name__ == '__main__':
    print('Combination Sum:', combination_sum([2,3,6,7], 7))

# Time Complexity: exponential
# Space Complexity: O(target/min(candidates))
