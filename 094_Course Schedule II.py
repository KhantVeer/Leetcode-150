"""
Course Schedule II
Return course order using topological sort or empty list if impossible.
"""
from collections import deque, defaultdict
from typing import List

def find_order(numCourses: int, prerequisites: List[List[int]]) -> List[int]:
    g = defaultdict(list); indeg=[0]*numCourses
    for a,b in prerequisites:
        g[b].append(a); indeg[a]+=1
    q = deque([i for i in range(numCourses) if indeg[i]==0])
    res=[]
    while q:
        u=q.popleft(); res.append(u)
        for v in g[u]:
            indeg[v]-=1
            if indeg[v]==0: q.append(v)
    return res if len(res)==numCourses else []

if __name__ == '__main__':
    print('Order:', find_order(4, [[1,0],[2,0],[3,1],[3,2]]))

# Time Complexity: O(N+E)
# Space Complexity: O(N+E)
