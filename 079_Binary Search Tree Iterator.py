"""
Binary Search Tree Iterator
Implement an iterator over a BST that returns the next smallest element (in-order).
"""
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BSTIterator:
    def __init__(self, root: Optional[TreeNode]):
        self.stack = []
        self.push_left(root)
    def push_left(self, node):
        while node:
            self.stack.append(node)
            node = node.left
    def next(self) -> int:
        node = self.stack.pop()
        val = node.val
        self.push_left(node.right)
        return val
    def hasNext(self) -> bool:
        return len(self.stack)>0

if __name__ == '__main__':
    root = TreeNode(7)
    root.left = TreeNode(3)
    root.right = TreeNode(15)
    root.right.left = TreeNode(9)
    root.right.right = TreeNode(20)
    it = BSTIterator(root)
    print(it.next())
    print(it.next())
    print(it.hasNext())
    print(it.next())
    print(it.hasNext())

# Time Complexity: next() amortized O(1), hasNext() O(1)
# Space Complexity: O(h)
