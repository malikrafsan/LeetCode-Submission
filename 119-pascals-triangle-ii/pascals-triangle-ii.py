class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        mat = [[] for _ in range(rowIndex+2)]

        mat[0] = [1]
        for i in range(1, rowIndex+2):
            mat[i] = [1] * (i+1)
            for j in range(1,i):
                mat[i][j] = mat[i-1][j-1] + mat[i-1][j]
            
        
        return mat[rowIndex]

