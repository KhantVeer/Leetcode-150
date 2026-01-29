"""
Lowest Common Ancestor of a Binary Tree
Find LCA of two nodes in binary tree.
"""
from typing import Optional

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val; self.left=left; self.right=right

def lowestCommonAncestor(root: Optional[TreeNode], p: TreeNode, q: TreeNode) -> Optional[TreeNode]:
    if not root or root==p or root==q: return root
    L = lowestCommonAncestor(root.left, p, q)
    R = lowestCommonAncestor(root.right, p, q)
    if L and R: return root
    return L or R

if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    p = root.left; q = root.left.right.right
    ans = lowestCommonAncestor(root,p,q)
    print('LCA:', ans.val if ans else None)  # 5

# Time Complexity: O(n)
# Space Complexity: O(h)
