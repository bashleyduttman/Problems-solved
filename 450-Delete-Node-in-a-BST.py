# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        def check(root):
            if root.left is None and root.right is None:
                return None
            elif root.left and root.right:
                
                r=find(root.left)
                r.right=root.right
                return root.left
            elif root.left:
                return root.left
            elif root.right:
                return root.right
        new=root
        def find(root):
            if root.right is None:
                return root
            return find(root.right)
        if root is None:
            return None
        if root.val==key:
            return check(root)
        while root:
            if root.val>key:
                if root.left and root.left.val==key:
                    root.left=check(root.left)
                else:
                    root=root.left
            else:
                if root.right and root.right.val==key:
                    root.right=check(root.right)
                else:
                    root=root.right
        return new


                        


        