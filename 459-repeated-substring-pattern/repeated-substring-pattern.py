class Solution:
    def check(self, s: str, length: int) -> bool:
        if len(s) % length != 0:
            return False

        for i in range(length, len(s)):
            prev = s[i % length]
            if s[i] != prev:
                return False
        
        return True

    def repeatedSubstringPattern(self, s: str) -> bool:
        for i in range(1,len(s)//2+1):
            if self.check(s, i):
                return True
        
        return False
    