class Solution:
    def climbStairs(self, n: int) -> int:
        def inner(n: int, memo) -> int:
            if n == 1:
                return 1
            if n == 2:
                return 2       

            m = memo.get(n, -1)
            if m != -1:
                return m

            res = inner(n-1, memo) + inner(n-2, memo)
            memo[n] = res
            return res
        
        return inner(n, {})

        

