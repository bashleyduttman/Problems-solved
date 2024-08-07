# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        op=0
        def dfs(root,sumi):
            nonlocal op
            if sumi==targetSum:
                op+=1
            
            if root.left is None and root.right is None:
                return 0
            l=0
            r=0
            if root.left:
                l=dfs(root.left,sumi+root.left.val)
            if root.right:
                r=dfs(root.right,sumi+root.right.val)
            return l+r
        
        def check(root):
            
            if root is None:
                return
            check(root.left)
            
            dfs(root,root.val)
            check(root.right)
        check(root)
        return op
        