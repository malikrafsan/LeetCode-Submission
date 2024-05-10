class Solution:
    def climbStairs(self, n: int) -> int:
        # if n == 1:
        #     return 1
        # if n == 2:
        #     return 2
        
        # return self.climbStairs(n-1) + self.climbStairs(n-2)

        arr = [0 for _ in range(max(n+1, 3))]
        arr[1] = 1
        arr[2] = 2

        for i in range(3, n+1):
            arr[i] = arr[i-1] + arr[i-2]
        
        return arr[n]

