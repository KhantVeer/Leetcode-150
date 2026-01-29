"""
Minimum Genetic Mutation
Find minimum mutations from start to end using BFS over valid bank strings.
"""
from collections import deque
from typing import List

def min_mutation(start: str, end: str, bank: List[str]) -> int:
    bank_set = set(bank)
    if end not in bank_set: return -1
    chars = 'ACGT'
    q = deque([(start,0)])
    vis = {start}
    while q:
        s,d = q.popleft()
        if s == end: return d
        for i in range(len(s)):
            for c in chars:
                if c == s[i]: continue
                t = s[:i] + c + s[i+1:]
                if t in bank_set and t not in vis:
                    vis.add(t); q.append((t,d+1))
    return -1

if __name__ == '__main__':
    print('Min mutation:', min_mutation('AACCGGTT','AACCGGTA',['AACCGGTA']))

# Time Complexity: O(N * L * 4)
# Space Complexity: O(N)
