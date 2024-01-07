class Solution:
    def romanToInt(self, s: str) -> int:
        mp = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }

        num = 0
        idx = 0
        n = len(s)

        while idx < n:
            char = s[idx]
            cur_val = mp[char]
            
            if idx == n-1:
                num += cur_val
                break
            
            next_val = mp[s[idx+1]]
            if next_val > cur_val:
                num += (next_val - cur_val)
                idx+=2
            else:
                num += cur_val
                idx+=1

        return num
            
