class Solution:
    def isPalindrome(self, x: int) -> bool:        
        sx = str(x)

        for i in range(len(sx)//2):
            if sx[i] != sx[len(sx)-i-1]:
                return False
        
        return True