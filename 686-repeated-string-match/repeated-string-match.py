class Solution:
    def check(self, a: str, b: str, fi: int) -> int:
        la = len(a)
        lb = len(b)

        cnt = 0
        for idx, c in enumerate(b):
            # idx = 3, c = 'b', fi=2, la=4
        
            if c != a[(idx + fi) % la]:
                return -1

        added = 0
        if fi != 0:
            lb = lb-(la-fi)
            added = 1
        
        mul = lb // la
        rest = 1 if lb % la != 0 else 0
        return added + mul + rest

    def repeatedStringMatch(self, a: str, b: str) -> int:
        if len(a) >= len(b):
            if b in a: return 1
            if b in a+a: return 2
            return -1

        mp = {}
        for i, c in enumerate(a):
            if c in mp:
                mp[c].append(i)
            else:
                mp[c] = [i]
        
        arr = mp.get(b[0], [])
        print("arr", arr)
        for idx in arr:
            res = self.check(a, b, idx)
            if res != -1: return res
        
        return -1


