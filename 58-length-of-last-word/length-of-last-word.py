class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        out = 0
        reset = False

        for char in s:
            if char != ' ':
                if reset:
                    out = 0
                    reset = False
                out += 1
            else:
                reset = True
        
        return out
        
