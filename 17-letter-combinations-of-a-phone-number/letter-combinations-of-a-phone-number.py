class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        mp = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        res = []

        # process
        for digit in digits:
            if len(res) == 0:
                res = mp[digit]
                continue
            
            arr = mp[digit]
            newres = []
            for x in res:
                for y in arr:
                    newres.append(x+y)
            
            res = newres

        return res