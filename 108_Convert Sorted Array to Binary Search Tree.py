"""
Convert Sorted Array to Binary Search Tree
Build a height-balanced BST from a sorted array.
"""
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sorted_array_to_bst(nums: List[int]) -> Optional[TreeNode]:
    def build(l, r):
        if l > r: return None
        mid = (l + r)//2
        node = TreeNode(nums[mid])
        node.left = build(l, mid-1)
        node.right = build(mid+1, r)
        return node
    return build(0, len(nums)-1)

def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []

if __name__ == '__main__':
    nums = [-10,-3,0,5,9]
    root = sorted_array_to_bst(nums)
    print('Inorder:', inorder(root))

# Time Complexity: O(n)
# Space Complexity: O(log n)
