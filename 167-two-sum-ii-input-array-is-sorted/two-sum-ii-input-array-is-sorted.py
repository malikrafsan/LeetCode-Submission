class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        l, r = 0, n-1

        while True:
            key = numbers[l] + numbers[r] - target
            if key == 0:
                return [l+1,r+1]
            elif key > 0:
                r -= 1
            else:
                l += 1

