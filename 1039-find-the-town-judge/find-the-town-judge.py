class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        arr = [[] for _ in range(n+1)]

        # [[], [], [1], [2]]

        for t in trust:
            arr[t[0]] = None
            if arr[t[1]] is None:
                continue

            arr[t[1]].append(t[0])

        for i in range(1, n+1):
            elmt = arr[i]
            if elmt is None:
                continue

            if len(elmt) != (n-1):
                continue
            
            flag = True
            for x in elmt:
                if x == i:
                    flag = False
                    break
            
            if flag:
                return i
        
        return -1

