class Solution:
    def isPalindrome(self, s: str) -> bool:
        clean = s
        for i in range(len(clean) // 2):
            c1 = clean[i]
            c2 = clean[len(clean)-i-1]

            if c1 != c2:
                return False
        
        return True

    def validPalindrome(self, s: str) -> bool:
        n = len(s)

        idx1 = 0
        idx2 = n-1

        lives = 1

        while idx1 < idx2:
            c1 = s[idx1]
            c2 = s[idx2]

            if c1 != c2:
                return self.isPalindrome(s[idx1+1:idx2+1]) or self.isPalindrome(s[idx1:idx2])
        
            idx1 += 1
            idx2 -= 1

        return True
