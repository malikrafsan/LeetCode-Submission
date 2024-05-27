class Solution:
    def bfs(self, row: int, col: int) -> int:
        visited = [
            [False for _ in range(self.col)]
            for _ in range(self.row)
        ]

        queue = deque()
        queue.append((row, col))
        total = 0

        direction = [(-1,0), (1,0),(0,-1),(0,1)]
        while True:
            if len(queue) <= 0:
                break
        
            row, col = queue.popleft()
            if visited[row][col]:
                continue

            visited[row][col] = True

            for dr in direction:
                i = row + dr[0]
                j = col + dr[1]
                if i < 0 or i >= self.row or j < 0 or j >= self.col:
                    total += 1
                    continue
                
                if self.grid[i][j] == 0:
                    total += 1
                else:
                    queue.append((i, j))

        return total

    def islandPerimeter(self, grid: List[List[int]]) -> int:
        # find first 1
        # then bfs from there

        self.row = len(grid)
        self.col = len(grid[0])
        self.grid = grid

        for i in range(self.row):
            for j in range(self.col):
                if grid[i][j] == 1:
                    return self.bfs(i, j)
        
        return -1
