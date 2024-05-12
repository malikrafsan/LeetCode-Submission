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
        q = deque()
        q.append([root]) # queue<list>
        while len(q) != 0:
            cur = q[0]
            q.pop()

            result.append(cur[-1].val)

            new_level = []
            for c in cur:
                if c.left is not None:
                    new_level.append(c.left)
                if c.right is not None:
                    new_level.append(c.right)
            
            if len(new_level) != 0:
                q.append(new_level)

        return result


