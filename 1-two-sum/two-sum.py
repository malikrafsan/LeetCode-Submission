class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevMap = {}

        for i in range(len(nums)):
            num = nums[i]
            diff = target - num

            if diff in prevMap:
                return [prevMap[diff], i]
            
            prevMap[num] = i
        
        return []
