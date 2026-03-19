#  https: // leetcode.com/problems/add-two-numbers/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l1s = []
        while l1 is not None:
            l1s.append(l1.val)
            l1 = l1.next

        l2s = []
        while l2 is not None:
            l2s.append(l2.val)
            l2 = l2.next

        curr = l1s[0] + l2s[0]
        last = ListNode(curr % 10)
        first = last
        del l1s[0]
        del l2s[0]
        rem = curr // 10
        while True:
            if len(l1s) == 0 and len(l2s) == 0:
                break
            curr = rem
            if len(l1s) > 0:
                curr += l1s[0]
                del l1s[0]
            if len(l2s) > 0:
                curr += l2s[0]
                del l2s[0]

            last.next = ListNode(curr % 10)
            last = last.next
            rem = curr//10

        if rem > 0:
            last.next = ListNode(rem)

        return first
