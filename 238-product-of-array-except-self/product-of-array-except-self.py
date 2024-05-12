# Input: nums = [1,2,3,4]
# Output: [24,12,8,6]

# [1,1,2,6,24]
# [24,24,12,4,1]

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [1 for _ in range(n+1)]
        postfix = [1 for _ in range(n+1)]
        result = [-1 for _ in range(n)]

        for i in range(n):
            prefix[i+1] = prefix[i] * nums[i]
        for i in range(n):
            postfix[n-i-1] = postfix[n-i] * nums[n-i-1]

        print(prefix, postfix)

        for i in range(n):
            result[i] = prefix[i] * postfix[i+1]

        return result
