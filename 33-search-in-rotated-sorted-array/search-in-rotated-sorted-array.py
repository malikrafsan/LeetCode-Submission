class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # n = len(nums)

        # res = nums[0]
        # left, right = 0, n-1

        # while left <= right:
        #     if nums[left] < nums[right]:
        #         res = min(res, nums[left])
        #         break
            
        #     mid = (left + right) // 2
        #     res = min(res, nums[mid])

        #     if nums[mid] >= nums[left]:
        #         left = mid + 1
        #     else:
        #         right = mid - 1
            
        # return res

        n = len(nums)
        left, right = 0, n-1

        while left <= right:
            mid = (left+right) // 2

            if nums[mid] == target:
                return mid
            
            if nums[mid] < nums[right]:
                if target > nums[mid] and target <= nums[right]:
                    left = mid+1
                else:
                    right = mid-1
            else:
                if target >= nums[left] and target < nums[mid]:
                    right = mid-1
                else:
                    left = mid+1

        return -1 


