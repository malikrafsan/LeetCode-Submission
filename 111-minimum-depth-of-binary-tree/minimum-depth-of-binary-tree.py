# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDepthRec(self, root: Optional[TreeNode], current: int) -> int:
        if root.left is None and root.right is None:
            return current
        elif root.left is None:
            return self.minDepthRec(root.right, current+1)
        elif root.right is None:
            return self.minDepthRec(root.left, current+1)
        else:
            return min(
                self.minDepthRec(root.right, current+1),
                self.minDepthRec(root.left, current+1)
            )

    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        return self.minDepthRec(root, 1)
