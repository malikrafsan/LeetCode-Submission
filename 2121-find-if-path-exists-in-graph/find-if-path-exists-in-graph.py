class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        mp = {}
        for edge in edges:
            a = edge[0]
            b = edge[1]
            if a not in mp:
                mp[a] = [b]
            else:
                mp[a].append(b)

            if b not in mp:
                mp[b] = [a]
            else:
                mp[b].append(a)

        q = deque()
        q.append(source)

        visited = [False for _ in range(n)]

        while len(q) != 0:
            top = q.popleft()
            visited[top] = True
            if top == destination:
                return True

            for elmt in mp[top]:
                if visited[elmt]:
                    continue
                
                q.append(elmt)

        return False



