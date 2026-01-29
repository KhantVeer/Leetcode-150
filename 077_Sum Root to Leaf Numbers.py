"""
Sum Root to Leaf Numbers
Calculate the total of numbers represented by root-to-leaf paths.
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sum_numbers(root: Optional[TreeNode]) -> int:
    def dfs(node, cur):
        if not node: return 0
        cur = cur*10 + node.val
        if not node.left and not node.right:
            return cur
        return dfs(node.left, cur) + dfs(node.right, cur)
    return dfs(root,0)

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    print('Sum numbers:', sum_numbers(root))  # 25

# Time Complexity: O(n)
# Space Complexity: O(h)
