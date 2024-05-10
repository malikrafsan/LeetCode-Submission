class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        obj = {}
        for i in range(len(order)):
            obj[order[i]] = i
        
        def convert(s: str) -> list[int]:
            res = [0 for _ in range(len(s))]
            for i in range(len(s)):
                res[i] = obj[s[i]]
            
            return res
        
        converted = [convert(word) for word in words]
        print(converted)

        def isLower(lst1: list[int], lst2: list[int]) -> bool:
            n1 = len(lst1)
            n2 = len(lst2)

            n = min(n1, n2)
            for i in range(n):
                if lst1[i] < lst2[i]:
                    return True
                elif lst1[i] > lst2[i]:
                    return False
            
            return n1 <= n2

        for i in range(1, len(converted)):
            if not isLower(converted[i-1], converted[i]):
                return False
        
        return True
