"""
Binary Tree Maximum Path Sum
Find maximum sum of any path in a binary tree (path can start and end anywhere).
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.best = -10**18
        def dfs(node):
            if not node: return 0
            L = max(0, dfs(node.left))
            R = max(0, dfs(node.right))
            self.best = max(self.best, node.val + L + R)
            return node.val + max(L,R)
        dfs(root)
        return int(self.best)

if __name__ == '__main__':
    root = TreeNode(-10)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print('Max path sum:', Solution().maxPathSum(root))

# Time Complexity: O(n)
# Space Complexity: O(h)
