"""
Course Schedule
Determine if you can finish all courses given prerequisites (topological check).
"""
from collections import deque, defaultdict
from typing import List

def can_finish(numCourses: int, prerequisites: List[List[int]]) -> bool:
    g = defaultdict(list); indeg = [0]*numCourses
    for a,b in prerequisites:
        g[b].append(a); indeg[a]+=1
    q = deque([i for i in range(numCourses) if indeg[i]==0])
    seen=0
    while q:
        u = q.popleft(); seen+=1
        for v in g[u]:
            indeg[v]-=1
            if indeg[v]==0: q.append(v)
    return seen==numCourses

if __name__ == '__main__':
    print('Can finish:', can_finish(2, [[1,0]]))
    print('Can finish (cycle):', can_finish(2, [[1,0],[0,1]]))

# Time Complexity: O(N+E)
# Space Complexity: O(N+E)
