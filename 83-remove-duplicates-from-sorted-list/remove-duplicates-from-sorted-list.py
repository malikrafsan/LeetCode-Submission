# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        
        curval = head.val
        res = head

        while True:
            nxt = head.next
            if nxt is None:
                break

            if nxt.val == head.val:
                head.next = nxt.next
            else:
                head = head.next

        return res