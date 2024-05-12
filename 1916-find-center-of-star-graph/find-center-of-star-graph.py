class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        mp = {}
        
        edge1 = edges[0]
        edge2 = edges[1]

        arr = [edge1[0], edge1[1], edge2[0], edge2[1]]
        for elmt in arr:
            if elmt not in mp:
                mp[elmt] = 1
            else:
                mp[elmt] += 1
        
        for key in mp:
            if mp[key] == 2:
                return key

        return -1
