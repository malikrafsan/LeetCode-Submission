# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []

        def recur(node:  Optional[TreeNode]):
            if node is None:
                return
            
            recur(node.left)
            result.append(node.val)
            recur(node.right)
        
        recur(root)
        return result
    