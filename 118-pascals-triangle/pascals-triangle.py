class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = [None] * numRows

        res[0] = [1]
        for i in range(1,numRows):
            res[i] = [1] * (i+1)
            
            for j in range(1,i):
                res[i][j] = res[i-1][j-1] + res[i-1][j]
        
        return res
