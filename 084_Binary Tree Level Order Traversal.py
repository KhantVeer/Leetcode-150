"""
Binary Tree Level Order Traversal
Return level order traversal (BFS) of a binary tree's node values.
"""
from typing import Optional, List

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val; self.left=left; self.right=right

def level_order(root: Optional[TreeNode]) -> List[List[int]]:
    if not root: return []
    from collections import deque
    q = deque([root]); res=[]
    while q:
        n=len(q); row=[]
        for _ in range(n):
            node=q.popleft(); row.append(node.val)
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        res.append(row)
    return res

if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    for row in level_order(root): print(row)

# Time Complexity: O(n)
# Space Complexity: O(n)
