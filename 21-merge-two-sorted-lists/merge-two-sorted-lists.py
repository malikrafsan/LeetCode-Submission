# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None and list2 is None:
            return None
        
        if list1 is None:
            return list2
        
        if list2 is None:
            return list1

        head = list1
        if list1.val > list2.val:
            head = list2
            list2 = list2.next
        else:
            list1 = list1.next
        ptr = head
        
        while True:
            if list1 is None:
                while list2 is not None:
                    ptr.next = list2
                    list2 = list2.next
                    ptr = ptr.next
                break
            
            if list2 is None:
                while list1 is not None:
                    ptr.next = list1
                    list1 = list1.next
                    ptr = ptr.next
                break

            if list1.val > list2.val:
                ptr.next = list2
                list2 = list2.next
            else:
                ptr.next = list1
                list1 = list1.next
            
            ptr = ptr.next

        return head
        

