class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        ptr = 0

        for i in range(1,n):
            if nums[i] == nums[ptr]:
                continue
            
            ptr += 1
            nums[ptr] = nums[i]
        
        return ptr+1
            