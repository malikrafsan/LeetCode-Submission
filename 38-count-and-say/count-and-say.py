class Solution:
    def rle(self, s: str) -> str:
        cnt = [s[0], 1]
        res = ""

        for i in range(1, len(s)):
            if s[i] == cnt[0]:
                cnt[1] += 1
                continue
            
            res += "1"+cnt[0] if cnt[1] == 1 else str(cnt[1]) + cnt[0]
            cnt = [s[i], 1]

        res += "1"+cnt[0] if cnt[1] == 1 else str(cnt[1]) + cnt[0]
        return res
            

    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        
        res = self.rle(self.countAndSay(n-1))
        return res
