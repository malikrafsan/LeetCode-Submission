class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        arr = []
        while True:
            arr.append(x % 10)
            x = x//10

            if x == 0:
                break      

        for i in range(len(arr) // 2):
            if arr[i] != arr[len(arr) - i - 1]:
                return False

        return True        
