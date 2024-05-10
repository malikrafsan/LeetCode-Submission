# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepthRec(self, root: Optional[TreeNode], current: int) -> int:
        leftLevel = current if root.left is None else self.maxDepthRec(root.left, current+1)
        rightLevel = current if root.right is None else self.maxDepthRec(root.right, current+1)

        return max(leftLevel, rightLevel)


    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        return self.maxDepthRec(root, 1)

        