"""
Clone Graph
Return a deep copy of an undirected graph.
"""
from collections import deque
from typing import Optional

class Node:
    def __init__(self,val=0,neighbors=None):
        self.val = val
        self.neighbors = neighbors or []

def clone_graph(node: Optional[Node]) -> Optional[Node]:
    if not node: return None
    m = {node: Node(node.val)}
    q = deque([node])
    while q:
        cur = q.popleft()
        for nb in cur.neighbors:
            if nb not in m:
                m[nb] = Node(nb.val)
                q.append(nb)
            m[cur].neighbors.append(m[nb])
    return m[node]

if __name__ == '__main__':
    a = Node(1); b = Node(2)
    a.neighbors.append(b); b.neighbors.append(a)
    c = clone_graph(a)
    print('Cloned root val:', c.val if c else None)

# Time Complexity: O(N+E)
# Space Complexity: O(N)
