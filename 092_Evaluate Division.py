"""
Evaluate Division
Calculate equation values given variable pairs using graph and DFS.
"""
from typing import List
from collections import defaultdict, deque

def calc_equation(equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
    g = defaultdict(list)
    for (a,b),v in zip(equations, values):
        g[a].append((b,v)); g[b].append((a,1.0/v))
    def query(a,b):
        if a not in g or b not in g: return -1.0
        if a==b: return 1.0
        vis = set([a]); dq = deque([(a,1.0)])
        while dq:
            node,prod = dq.popleft()
            for nb,w in g[node]:
                if nb in vis: continue
                if nb==b: return prod * w
                vis.add(nb); dq.append((nb, prod*w))
        return -1.0
    return [query(a,b) for a,b in queries]

if __name__ == '__main__':
    eqs = [["a","b"],["b","c"]]
    vals = [2.0,3.0]
    queries = [["a","c"],["b","a"],["a","e"]]
    print('Results:', calc_equation(eqs, vals, queries))

# Time Complexity: O(Q*(V+E)) worst-case
# Space Complexity: O(V+E)
