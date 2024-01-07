class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        ptr = 0

        for num in nums:
            if num == val:
                continue
            
            nums[ptr] = num
            ptr += 1

        return ptr
