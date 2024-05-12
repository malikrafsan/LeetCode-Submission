class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        arr_open = []
        cnt = 0

        arr_s = [c for c in s]
        for idx, c in enumerate(arr_s):
            if c == "(":
                arr_open.append(idx)
                cnt += 1
            elif c == ")":
                if cnt > 0:
                    cnt -= 1
                else:
                    arr_s[idx] = None

        if cnt > 0:
            for i in range(cnt):
                idx = arr_open[-1-i]
                arr_s[idx] = None
        
        result = ""
        for c in arr_s:
            if c is None:
                continue
            
            result += c
        
        return result
