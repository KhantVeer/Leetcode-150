"""
Binary Tree Zigzag Level Order Traversal
Return zigzag level order (left-to-right then right-to-left alternation).
"""
from typing import Optional, List

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val; self.left=left; self.right=right

def zigzag_level_order(root: Optional[TreeNode]) -> List[List[int]]:
    if not root: return []
    from collections import deque
    q = deque([root]); res=[]
    left_to_right = True
    while q:
        n = len(q); row = [0]*n
        for i in range(n):
            node = q.popleft()
            idx = i if left_to_right else (n-1-i)
            row[idx] = node.val
            if node.left: q.append(node.left)
            if node.right: q.append(node.right)
        res.append(row)
        left_to_right = not left_to_right
    return res

if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    for row in zigzag_level_order(root): print(row)

# Time Complexity: O(n)
# Space Complexity: O(n)
