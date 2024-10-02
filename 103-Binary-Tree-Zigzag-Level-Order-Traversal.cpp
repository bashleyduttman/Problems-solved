/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>  q;
        
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        bool flg=1;
        while(!q.empty()){
            int size=q.size();
            vector<int> vec;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);

                }
                if(node->right){
                    q.push(node->right);
                }
                if(flg){
                    vec.push_back(node->val);
                }
                else{
                    vec.insert(vec.begin(),node->val);
                }
                
            }
            ans.push_back(vec);
            flg=!flg;

        }
        return ans;
    }
};