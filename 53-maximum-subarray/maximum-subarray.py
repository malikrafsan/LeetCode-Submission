class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cur_max, max_until_cur = float('-inf'), float('-inf')

        for num in nums:
            cur_max = max(num, cur_max + num)
            max_until_cur = max(max_until_cur, cur_max)
        
        return max_until_cur
        