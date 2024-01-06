# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = 0
        num2 = 0

        mul = 1
        while True:
            num1 += (l1.val * mul)
            mul *= 10

            if l1.next is None:
                break
            
            l1 = l1.next
        
        mul = 1
        while True:
            num2 += (l2.val * mul)
            mul *= 10

            if l2.next is None:
                break
            
            l2 = l2.next
        
        num3 = num1 + num2
        ret = ListNode(num3 % 10, None)
        res = ret
        
        while True:
            num3 //= 10

            if num3 == 0:
                break
            
            new_node = ListNode(num3%10, None)
            res.next = new_node
            res = new_node

        return ret
        
            