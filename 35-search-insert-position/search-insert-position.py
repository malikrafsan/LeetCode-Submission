class Solution:
    def binarySearch(self, arr, l, r, x):
        while l <= r:
            mid = l + (r - l) // 2

            if arr[mid] == x:
                return mid
            
            if arr[mid] < x:
                l = mid + 1
            else:
                r = mid - 1

        return -1

    def searchInsert(self, nums: List[int], target: int) -> int:
        l = 0
        r = len(nums)-1
        mid = -1

        while l <= r:
            mid = l + ((r-l)//2)

            if nums[mid] == target:
                return mid
            
            if nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        
        return l

