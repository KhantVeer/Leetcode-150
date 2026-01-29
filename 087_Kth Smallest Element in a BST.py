"""
Kth Smallest Element in a BST
Return the k-th smallest element using inorder traversal.
"""
from typing import Optional

class TreeNode:
    def __init__(self,val=0,left=None,right=None):
        self.val=val; self.left=left; self.right=right

def kth_smallest(root: Optional[TreeNode], k: int) -> int:
    stack=[]; cur=root
    while cur or stack:
        while cur:
            stack.append(cur); cur=cur.left
        cur = stack.pop(); k-=1
        if k==0: return cur.val
        cur = cur.right
    return -1

if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.left.right = TreeNode(2)
    print('kth smallest k=1:', kth_smallest(root,1))
    print('kth smallest k=3:', kth_smallest(root,3))

# Time Complexity: O(h + k)
# Space Complexity: O(h)
