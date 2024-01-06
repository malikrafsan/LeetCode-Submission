class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        ret = float('-inf')

        prefix = 1
        for num in nums:
            prefix *= num
            ret = max(ret, prefix)
            
            if prefix == 0:
                prefix = 1
        
        postfix = 1
        for i in range(len(nums)-1,-1,-1):
            num = nums[i]

            postfix *= num
            ret = max(ret, postfix)

            if postfix == 0:
                postfix = 1
        
        return ret
