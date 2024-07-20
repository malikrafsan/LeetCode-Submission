class Solution:
    mp = {}

    def uniquePaths(self, m: int, n: int) -> int:
        if m > n:
            return self.uniquePaths(n, m)

        if f"{m}-{n}" in self.mp:
            return self.mp[f"{m}-{n}"]
        
        if m == 1:
            return 1
        if n == 1:
            return 1

        res = self.uniquePaths(m-1, n) + self.uniquePaths(m, n-1)
        self.mp[f"{m}-{n}"] = res
        return res
