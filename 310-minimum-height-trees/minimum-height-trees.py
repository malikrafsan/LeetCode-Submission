class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if (len(edges) == 0):
            return [0]
        
        mp = {i: set() for i in range(n)}
        for edge in edges:
            mp[edge[0]].add(edge[1])
            mp[edge[1]].add(edge[0])
        
        leaves = []
        for d in mp:
            if len(mp[d]) == 1:
                leaves.append(d)
        
        while True:
            if n <= 2:
                break
            
            n -= len(leaves)
            new_leaves = []
            for leaf in leaves:
                neighbor = list(mp[leaf])[0]
                mp[neighbor].remove(leaf)

                if len(mp[neighbor]) == 1:
                    new_leaves.append(neighbor)
            
            leaves = new_leaves

        return leaves
