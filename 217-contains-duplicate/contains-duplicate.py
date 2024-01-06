class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        num_set = set()

        for i in range(len(nums)):
            num = nums[i]

            if num in num_set:
                return True
            
            num_set.add(num)
        
        return False
