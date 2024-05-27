class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        ans = [0 for _ in range(n)]
        stack = []
        prev_time = 0

        for log in logs:
            fn, typ, stamp = log.split(":")
            fn = int(fn)
            stamp = int(stamp)

            if typ == "start":
                if len(stack) > 0:
                    top = stack[-1]
                    ans[top] += stamp - prev_time
                
                stack.append(fn)
                prev_time = stamp
            else:
                top = stack[-1]
                stack.pop()
                
                ans[top] += stamp - prev_time + 1
                prev_time = stamp + 1
        
        return ans



