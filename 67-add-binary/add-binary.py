class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n1 = len(a)
        n2 = len(b)

        idx1 = n1-1
        idx2 = n2-1

        continuing = False
        res = ""
        while True:
            if idx1 < 0 or idx2 < 0:
                break
            
            c1 = a[idx1]
            c2 = b[idx2]

            ctr = 1 if continuing else 0
            continuing = False

            ctr += 1 if c1 == "1" else 0
            ctr += 1 if c2 == "1" else 0

            if ctr % 2 == 0:
                res = "0" + res
            else:
                res = "1" + res
            
            if ctr >= 2:
                continuing = True
            
            idx1 -= 1
            idx2 -= 1

        while True:
            if idx1 < 0:
                break

            c1 = a[idx1]

            ctr = 1 if continuing else 0
            continuing = False

            ctr += 1 if c1 == "1" else 0

            if ctr % 2 == 0:
                res = "0" + res
            else:
                res = "1" + res

            if ctr >= 2:
                continuing = True
            
            idx1 -= 1

        while True:
            if idx2 < 0:
                break

            c2 = b[idx2]

            ctr = 1 if continuing else 0
            continuing = False

            ctr += 1 if c2 == "1" else 0

            if ctr % 2 == 0:
                res = "0" + res
            else:
                res = "1" + res
            
            if ctr >= 2:
                continuing = True
            
            idx2 -= 1

        if continuing:
            res = "1" + res

        return res


