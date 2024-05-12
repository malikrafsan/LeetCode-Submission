class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)
        new_mat = [[-1 for i in range(n-2)] for j in range(n-2)]

        for i in range(1, n-1):
            for j in range(1, n-1):
                for a in range(-1, 2):
                    for b in range(-1, 2):
                        new_mat[i-1][j-1] = max(new_mat[i-1][j-1], grid[i+a][j+b])
        
        return new_mat

         