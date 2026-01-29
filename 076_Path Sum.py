"""
Path Sum
Check if the binary tree has a root-to-leaf path with given sum.
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def has_path_sum(root: Optional[TreeNode], target: int) -> bool:
    if not root: return False
    if not root.left and not root.right:
        return root.val == target
    return has_path_sum(root.left, target - root.val) or has_path_sum(root.right, target - root.val)

if __name__ == '__main__':
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(8)
    root.left.left = TreeNode(11)
    root.left.left.left = TreeNode(7)
    root.left.left.right = TreeNode(2)
    root.right.left = TreeNode(13)
    root.right.right = TreeNode(4)
    root.right.right.right = TreeNode(1)
    print('Has path sum 22:', has_path_sum(root, 22))
    print('Has path sum 26:', has_path_sum(root, 26))
    print('Has path sum 18:', has_path_sum(root, 18))

# Time Complexity: O(n)
# Space Complexity: O(h)
