class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = nums[0]

        for i in range(1, len(nums)):
            num = nums[i]
            res = res ^ num
        
        return res
