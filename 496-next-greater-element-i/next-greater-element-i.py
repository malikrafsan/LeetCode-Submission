class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        mp = {}
        stack = []

        for num2 in nums2:
            while True:
                if len(stack) == 0 or stack[-1] > num2:
                    break
                
                mp[stack[-1]] = num2
                stack.pop()

            stack.append(num2)
            
        for i, num1 in enumerate(nums1):
            nums1[i] = mp.get(num1, -1)
        
        return nums1
    