"""
Binary Tree Right Side View
Return node values visible from the right side, level by level.
"""
from typing import Optional, List

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val; self.left=left; self.right=right

def right_side_view(root: Optional[TreeNode]) -> List[int]:
    if not root: return []
    from collections import deque
    q = deque([root])
    res = []
    while q:
        n = len(q)
        for i in range(n):
            node = q.popleft()
            if i==n-1: res.append(node.val)
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
    return res

if __name__ == '__main__':
    root = TreeNode(1)
    root.right = TreeNode(3)
    root.left = TreeNode(2)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(4)
    print('Right side view:', right_side_view(root))

# Time Complexity: O(n)
# Space Complexity: O(n)
