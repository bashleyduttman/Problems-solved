# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
       arr=preorder(root,[0,0])
       return max(arr[0],arr[1])
        
        
def preorder(root,arr):
    if(not root):
        return [0,0]
    opt1=preorder(root.left,arr)
    opt2=preorder(root.right,arr)
    c=root.val+opt1[1]+opt2[1]
    r=max(opt1[0],opt1[1])+max(opt2[0],opt2[1])
    return [c,r]

