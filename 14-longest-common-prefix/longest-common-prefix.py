class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        lns = [len(s) for s in strs]
        min_ln = min(lns)

        out = ""
        for i in range(min_ln):
            pivot = strs[0][i]

            for j in range(1, len(strs)):
                if strs[j][i] != pivot:
                    return out
            
            out += pivot
        
        return out
        