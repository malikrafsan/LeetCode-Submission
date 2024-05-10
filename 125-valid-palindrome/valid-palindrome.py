class Solution:
    def isPalindrome(self, s: str) -> bool:
        sl = s.lower()
        clean = []
        for c in sl:
            if c not in "abcdefghijklmnopqrstuvwxyz1234567890":
                continue

            clean.append(c)

        for i in range(len(clean) // 2):
            c1 = clean[i]
            c2 = clean[len(clean)-i-1]

            if c1 != c2:
                return False
        
        return True