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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mpp;
        int maxi=0;
        vector<int>ans;
        order(root,mpp);
        for(auto it:mpp){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
            else if(it.second>maxi){
                ans.clear();
                maxi=it.second;
                ans.push_back(it.first);
            }
        }
        return ans;


    }
    int order(TreeNode*root,unordered_map<int,int>&mpp){
        if(root==NULL)return 0;
        int total=order(root->left,mpp)+order(root->right,mpp)+root->val;
        mpp[total]++;
        return total;
    }
};