class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        mp = {} # remainder -> index
        mp[0] = -1

        curSum = 0
        for i, num in enumerate(nums):
            curSum += num
            remainder = curSum % k

            if remainder not in mp:
                mp[remainder] = i
            else:
                idx = mp[remainder]
                if i - idx >= 2:
                    return True

        return False



