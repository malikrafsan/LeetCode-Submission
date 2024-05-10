class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # ai = int(a, 2)
        # bi = int(b, 2)

        # si = ai + bi

        # return bin(si)[2:]

        n1 = len(a)
        n2 = len(b)

        idx1 = n1-1
        idx2 = n2-1

        continuing = False
        res = ""
        while True:
            if idx1 < 0 and idx2 < 0 and (not continuing):
                break
            
            ctr = 0
            if continuing:
                ctr += 1
                continuing = False

            if idx1 >= 0:
                c1 = a[idx1]
                ctr += 1 if c1 == "1" else 0
                idx1 -= 1
            
            if idx2 >= 0:
                c2 = b[idx2]
                ctr += 1 if c2 == "1" else 0
                idx2 -= 1

            if ctr % 2 == 0:
                res += "0"
            else:
                res += "1"
            
            if ctr >= 2:
                continuing = True

        return res[::-1]


