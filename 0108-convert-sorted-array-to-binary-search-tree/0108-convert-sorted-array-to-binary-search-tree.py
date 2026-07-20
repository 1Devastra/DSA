# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: Optional[TreeNode]
        """
        def bst(start,end):
            if start>end:
                return None
            mid=(start+end)/2
            root=TreeNode(nums[mid])
            root.left=bst(start,mid-1)
            root.right=bst(mid+1,end)
            return root
        return bst(0,len(nums)-1)
        