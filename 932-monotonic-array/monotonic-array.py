class Solution:
    def isIncreasing(self, nums: List[int]) -> bool:
        for i in range(1, len(nums)):
            if nums[i-1] > nums[i]:
                return False
        return True

    def isDecreasing(self, nums: List[int]) -> bool:
        for i in range(1, len(nums)):
            if nums[i-1] < nums[i]:
                return False
        return True

    def isMonotonic(self, nums: List[int]) -> bool:
        return self.isIncreasing(nums) or self.isDecreasing(nums)
        