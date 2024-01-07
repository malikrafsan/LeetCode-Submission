class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        ln1 = len(s)
        ln2 = len(t)

        if ln1 != ln2:
            return False
        
        pivot = ord('a')
        lookup1 = [0] * 26
        lookup2 = [0] * 26

        for i in range(ln1):
            lookup1[ord(s[i]) - pivot] += 1
            lookup2[ord(t[i]) - pivot] += 1

        for i in range(26):
            if lookup1[i] != lookup2[i]:
                return False
        
        return True