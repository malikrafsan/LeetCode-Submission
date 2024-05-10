class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        idx1 = len(s)-1
        idx2 = len(t)-1

        cnt1 = 0
        cnt2 = 0

        while True:
            while True:
                if idx1 < 0:
                    break
                
                c1 = s[idx1]
                if c1 == '#':
                    cnt1 += 1
                    idx1 -= 1
                    continue
                
                if cnt1 <= 0:
                    break

                cnt1 -= 1
                idx1 -= 1

            while True:
                if idx2 < 0:
                    break
                
                c2 = t[idx2]
                if c2 == '#':
                    cnt2 += 1
                    idx2 -= 1
                    continue
                
                if cnt2 <= 0:
                    break

                cnt2 -= 1
                idx2 -= 1

            if idx1 < 0 or idx2 < 0:
                break
            
            if s[idx1] != t[idx2]:
                return False
            
            idx1 -= 1
            idx2 -= 1
        
        return idx1 < 0 and idx2 < 0

        # while True:
        #     if idx1 < 0 or idx2 < 0:
        #         break
            
        #     cnt1 = 0
        #     while True:
        #         if idx1 < 0:
        #             break

        #         c1 = s[idx1]
        #         if c1 != '#':
        #             break
        #         cnt1 += 1
        #         idx1 -= 1


        #     if s[idx1] == '#':
        #         continue

        #     cnt2 = 0
        #     while True:
        #         if idx2 < 0:
        #             break
                
        #         c2 = t[idx2]
        #         if c2 != '#':
        #             break
        #         cnt2 += 1
        #         idx2 -= 1
            
        #     idx2 -= cnt2
        #     if t[idx2] == '#':
        #         continue
            
        #     if s[idx1] != t[idx2]:
        #         return False
            
        #     idx1 -= 1
        #     idx2 -= 1

        # return True
    