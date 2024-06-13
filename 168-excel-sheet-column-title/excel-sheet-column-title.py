class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        if columnNumber <= 0: return ""

        arr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        n = len(arr)

        res = ""
        while True:
            if columnNumber <= 0: break

            left = columnNumber % n
            columnNumber = (columnNumber-1) // n

            res = arr[left-1] + res
        
        return res
    