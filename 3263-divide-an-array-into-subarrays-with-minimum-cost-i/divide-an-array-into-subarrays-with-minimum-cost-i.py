class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        # find the lowest and second lowest
        # element

        first_lowest = -1 #idx
        second_lowest = -1

        for i in range(1, len(nums)):
            if first_lowest == -1:
                first_lowest = i
                continue
            elif first_lowest != -1 and second_lowest == -1:
                # second_lowest = i
                if nums[first_lowest] > nums[i]:
                    second_lowest = first_lowest
                    first_lowest = i
                else:
                    second_lowest = i
                continue

            cur = nums[i]
            if cur <= nums[first_lowest]:
                second_lowest = first_lowest
                first_lowest = i
            elif cur <= nums[second_lowest]:
                second_lowest = i
        
        return nums[0] + nums[first_lowest] + nums[second_lowest]
