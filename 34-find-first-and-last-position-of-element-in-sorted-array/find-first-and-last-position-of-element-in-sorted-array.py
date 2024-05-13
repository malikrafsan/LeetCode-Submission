class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        # list [lowerbound, upperbound]

        # bruteforce
        # iterate the nums
        # if we found the first target, store in lowerbound
        # if we found larger element than the target, store it - 1 in upperbound

        if len(nums) == 0:
            return [-1,-1]

        def lower_bound():
            left = 0
            right = len(nums) - 1

            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] >= target:
                    right = mid - 1
                else:
                    left = mid + 1
            
            return left

        def upper_bound():
            left = 0
            right = len(nums) - 1

            while left <= right:
                mid = left + (right - left) // 2
                if nums[mid] <= target:
                    left = mid + 1
                else:
                    right = mid - 1
            
            return right

        left = lower_bound()
        right = upper_bound()
        
        if left < 0 or left >= len(nums) or nums[left] != target:
            return [-1, -1]
        
        return [left, right]
