# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None

        if head.next is None:
            return head
        
        prevRoot = ListNode()
        prevRoot.next = head
        prevWalker = prevRoot

        ptr1 = head # 1
        ptr2 = head.next # 2
        while True:
            print(ptr1.val, ptr2.val)
            prevWalker.next = ptr2 # 2
            ptr1.next = ptr2.next # 3
            ptr2.next = ptr1
            prevWalker = ptr1
            print(ptr1.val, ptr2.val)

            # shift ptr1 and ptr2
            ptr1 = ptr1.next # 3
            if ptr1 is None:
                break
            
            ptr2 = ptr1.next
            if ptr2 is None:
                break
            

        return prevRoot.next


        
