class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """        
        idx1 = 0 # real idx
        idx2 = 0 # idx without zero

        n = len(nums)
        while True:            
            while True:
                if idx1 != n:
                    if nums[idx1] != 0:
                        break
                    
                    idx1 += 1
                else:
                    while idx2 != n:                        
                        nums[idx2] = 0
                        idx2 += 1
                    return
            
            nums[idx2] = nums[idx1]
            idx1 += 1
            idx2 += 1

