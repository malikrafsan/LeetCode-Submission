# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        l = 1
        r = n

        last_mid = -1
        while l <= r:
            mid = (l + r) // 2

            flag = isBadVersion(mid)
            if flag:
                last_mid = mid
                r = mid-1
            else:
                l = mid + 1
        
        return last_mid
