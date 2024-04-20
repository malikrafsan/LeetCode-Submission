class Solution:
    # def add(self, added: str): 
    #     self.res.append(added)
    # def pop(self): 
    #     if len(self.res) > 1: 
    #         self.res.pop()

    def simplifyPath(self, path: str) -> str:
        lst = path.split("/")
        res = [""]

        for i in range(1, len(lst)):
            cur = lst[i]
            if cur in ["", "."]: continue
            if cur == "..": 
                # self.pop()
                if len(res) > 1:
                    res.pop()
                continue

            res.append(cur)

        return "/" if len(res) == 1 else "/".join(res)
