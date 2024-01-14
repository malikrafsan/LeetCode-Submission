class Solution:
    def mySqrt(self, x: int) -> int:
        cur = 1
        
        while True:
            exp = cur ** 2
            if exp == x:
                return cur
            if exp > x:
                return cur-1
            
            cur += 1
            