"""
Minimum Absolute Difference in BST
Find minimum absolute difference between values of any two nodes in a BST.
"""
from typing import Optional

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val; self.left=left; self.right=right

def get_minimum_difference(root: Optional[TreeNode]) -> int:
    prev = None; best = float('inf')
    def dfs(node):
        nonlocal prev, best
        if not node: return
        dfs(node.left)
        if prev is not None:
            best = min(best, node.val - prev)
        prev = node.val
        dfs(node.right)
    dfs(root)
    return int(best) if best!=float('inf') else 0

if __name__ == '__main__':
    root = TreeNode(1)
    root.right = TreeNode(3)
    root.right.left = TreeNode(2)
    print('Min abs diff:', get_minimum_difference(root))

# Time Complexity: O(n)
# Space Complexity: O(h)
