class Solution:
    def isIPv4(self, q: str) -> bool:
        arr = q.split(".")
        if len(arr) != 4:
            return False
        
        for elmt in arr:
            try:
                if len(elmt) == 0:
                    return False

                ielmt = int(elmt)
                if ielmt < 0 or ielmt > 255:
                    return False
                
                if ielmt != 0 and elmt[0] == '0':
                    return False
                
                if ielmt == 0 and len(elmt) != 1:
                    return False

            except:
                return False

        return True


    def isIPV6(self, q: str) -> bool:
        arr = q.split(':')
        if len(arr) != 8:
            return False
        
        for elmt in arr:
            n = len(elmt)
            if n < 1 or n > 4:
                return False

            for c in elmt:
                if c not in "1234567890abcdefABCDEF":
                    return False

        return True


    def validIPAddress(self, queryIP: str) -> str:
        if self.isIPv4(queryIP):
            return "IPv4"
        elif self.isIPV6(queryIP):
            return "IPv6"
        
        return "Neither"