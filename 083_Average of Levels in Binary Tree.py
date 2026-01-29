"""
Average of Levels in Binary Tree
Calculate average value of nodes on each level.
"""
from typing import Optional, List

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val; self.left=left; self.right=right

def average_of_levels(root: Optional[TreeNode]) -> List[float]:
    if not root: return []
    from collections import deque
    q = deque([root])
    res = []
    while q:
        n = len(q); s=0
        for _ in range(n):
            node = q.popleft(); s += node.val
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        res.append(s/n)
    return res

if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print('Averages:', average_of_levels(root))

# Time Complexity: O(n)
# Space Complexity: O(n)
