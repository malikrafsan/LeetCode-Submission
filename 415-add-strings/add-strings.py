class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = ""
        n1 = len(num1)
        n2 = len(num2)
        idx1 = n1-1 
        idx2 = n2-1
        carry = False

        while True:
            if idx1 < 0 and idx2 < 0 and (not carry):
                break
            
            cnt = 0
            if idx1 >= 0:
                cnt += int(num1[idx1])
                idx1 -= 1
            if idx2 >= 0:
                cnt += int(num2[idx2])
                idx2 -= 1
            if carry:
                cnt += 1
                carry = False
            
            if cnt >= 10:
                carry = True
                cnt %= 10
            
            res += str(cnt)
        
        return res[::-1]
