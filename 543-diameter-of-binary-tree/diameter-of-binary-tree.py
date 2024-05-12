# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:    
    def dfs(self, root: Optional[TreeNode]) -> int:
        # return longest path, but update self.mx as it the root

        if root.left is None and root.right is None:
            return 1

        left = 0 if root.left is None else self.dfs(root.left)
        right = 0 if root.right is None else self.dfs(root.right)

        as_root = left + right + 1
        if as_root > self.mx:
            self.mx = as_root

        return max(left, right) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.mx = 0

        res = self.dfs(root)

        print(self.mx)
        print(res)

        return max(self.mx, res) - 1
