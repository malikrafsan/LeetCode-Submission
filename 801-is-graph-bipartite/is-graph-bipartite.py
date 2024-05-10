class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        col = [-1 for _ in range(n)]

        for i in range(n):
            if col[i] != -1:
                continue
            
            q = deque()
            q.append((i,0))

            while q:
                node, color = q.popleft()

                if col[node] == -1:
                    col[node] = color
                    for nb in graph[node]:
                        q.append((nb, color^1))

                if col[node] != color:
                    return False
            
        return True
