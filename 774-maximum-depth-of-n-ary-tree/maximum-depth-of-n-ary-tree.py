"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepthRec(self, root: 'Node', current: int) -> int:
        mx = current
        for node in root.children:
            cur = current if node is None else self.maxDepthRec(node, current+1)
            mx = max(mx, cur)
        
        return mx

    def maxDepth(self, root: 'Node') -> int:
        if root is None:
            return 0
        
        return self.maxDepthRec(root, 1)
