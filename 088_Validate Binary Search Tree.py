"""
Validate Binary Search Tree
Check if a binary tree is a valid BST using min/max bounds.
"""
from typing import Optional

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val; self.left=left; self.right=right

def is_valid_bst(root: Optional[TreeNode], low=float('-inf'), high=float('inf')) -> bool:
    if not root: return True
    if not (low < root.val < high): return False
    return is_valid_bst(root.left, low, root.val) and is_valid_bst(root.right, root.val, high)

if __name__ == '__main__':
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(3)
    print('Is valid BST:', is_valid_bst(root))
    bad = TreeNode(5)
    bad.left = TreeNode(1)
    bad.right = TreeNode(4)
    bad.right.left = TreeNode(3)
    bad.right.right = TreeNode(6)
    print('Is valid BST:', is_valid_bst(bad))

# Time Complexity: O(n)
# Space Complexity: O(h)
