"""
Count Complete Tree Nodes
Count nodes in a complete binary tree efficiently using subtree heights.
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def height_left(node: Optional[TreeNode]) -> int:
    h = 0
    while node:
        h += 1
        node = node.left
    return h

def height_right(node: Optional[TreeNode]) -> int:
    h = 0
    while node:
        h += 1
        node = node.right
    return h

def count_nodes(root: Optional[TreeNode]) -> int:
    if not root: return 0
    hl = height_left(root)
    hr = height_right(root)
    if hl == hr:
        return (1<<hl) - 1
    return 1 + count_nodes(root.left) + count_nodes(root.right)

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    print('Count nodes:', count_nodes(root))  # 6

# Time Complexity: O((log n)^2)
# Space Complexity: O(log n)
