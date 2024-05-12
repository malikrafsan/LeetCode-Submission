class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {c: [] for c in range(numCourses)}
        for p in prerequisites:
            graph[p[0]].append(p[1])
        
        output = []
        visit = [False for _ in range(numCourses)]
        cycle = set()

        def dfs(src: int):
            if src in cycle:
                return False
            
            if visit[src]:
                return True
            
            cycle.add(src)
            for nb in graph[src]:
                if not dfs(nb):
                    return False
            
            cycle.remove(src)

            visit[src] = True
            output.append(src)
            return True
        
        for c in range(numCourses):
            if not dfs(c):
                return []
        
        return len(output) == numCourses
        