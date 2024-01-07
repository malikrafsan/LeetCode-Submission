class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        open_syms = ['(', '[', '{']
        close_syms = [')', ']', '}']

        for char in s:
            if char in open_syms:
                stack.append(char)
                continue
            
            if char in close_syms:
                if len(stack) == 0:
                    return False

                opening = stack.pop()
                idx_open = open_syms.index(opening)

                if close_syms[idx_open] != char:
                    return False

        return len(stack) == 0 
                
            

        