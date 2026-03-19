# https://leetcode.com/problems/binary-tree-right-side-view/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        r = []
        q = [[root, 0]]
        while True:
            curr = q[0]
            print("curr.v", curr[0].val)
            print("curr.l", curr[0].left)
            print("curr.r", curr[0].right)
            print("curr.level", curr[1])
            del q[0]
            if len(q) == 0 and curr[0].left is None and curr[0].right is None:
                # we're done
                # last is always right most
                r.append(curr[0].val)
                return r
            if curr[0].left is not None:
                q.append([curr[0].left, curr[1] + 1])
            if curr[0].right is not None:
                q.append([curr[0].right, curr[1] + 1])

            if curr[1] != q[0][1]:
                print("cur diff to next level", curr[1], q[0][1])
                r.append(curr[0].val)
            else:
                print("same level for", curr[0].val, q[0][0].val)
