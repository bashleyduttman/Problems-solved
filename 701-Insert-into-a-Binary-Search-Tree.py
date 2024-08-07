# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if(root is None):
            root=TreeNode(val)
            return root
        new=root
        while root:
            if(root.val<val):
                if(root.right):
                    root=root.right
                else:
                    val=TreeNode(val)
                    root.right=val
                    break
            else:
                if(root.left):
                    root=root.left
                else:
                    val=TreeNode(val)
                    root.left=val
                    break
    
        return new
        