"""
Construct Quad Tree
Construct a QuadTree from a 2D grid; leaf nodes when region uniform.
"""
from typing import List, Optional

class Node:
    def __init__(self, val: bool, isLeaf: bool, topLeft=None, topRight=None, bottomLeft=None, bottomRight=None):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight

def construct(grid: List[List[int]]) -> Optional[Node]:
    if not grid: return None
    n = len(grid)
    def build(r0, c0, size):
        if size == 1:
            return Node(bool(grid[r0][c0]), True)
        half = size // 2
        tl = build(r0, c0, half)
        tr = build(r0, c0+half, half)
        bl = build(r0+half, c0, half)
        br = build(r0+half, c0+half, half)
        if tl.isLeaf and tr.isLeaf and bl.isLeaf and br.isLeaf and tl.val == tr.val == bl.val == br.val:
            return Node(tl.val, True)
        return Node(False, False, tl, tr, bl, br)
    return build(0,0,n)

if __name__ == '__main__':
    g = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
    root = construct(g)
    print('Constructed quad tree root isLeaf:', root.isLeaf, 'val:', root.val)

# Time Complexity: O(n^2)
# Space Complexity: O(n^2)
