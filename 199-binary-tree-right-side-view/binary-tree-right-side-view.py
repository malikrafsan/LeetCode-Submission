# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        result = []
        current = [root]

        while True:
            result.append(current[-1].val)

            new_level = []
            for c in current:
                if c.left is not None:
                    new_level.append(c.left)
                if c.right is not None:
                    new_level.append(c.right)
            
            if len(new_level) == 0:
                break

            current = new_level

        return result


