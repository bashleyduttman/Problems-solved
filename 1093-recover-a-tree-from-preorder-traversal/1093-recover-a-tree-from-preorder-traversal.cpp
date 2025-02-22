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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*,int>>st;
        int l=0;
        int n=traversal.size();
        int num=0;
        while(l<n && isdigit(traversal[l])){
            num=num*10+(traversal[l]-'0');
            l++;
        }
        TreeNode* root=new TreeNode(num);
        int cnt=0;
        if(traversal.size()==0) return root;
        st.push({root,0});
        while(l<n){
            num=0;
            cnt=0;
            while(l<n && traversal[l]=='-'){
                cnt++;
                l++;
            }

            while(l<n && isdigit(traversal[l])){
                num=num*10+(traversal[l]-'0');
                l++;
            }
            
            if(st.top().second<cnt){
                TreeNode *temp1=st.top().first;
                temp1->left=new TreeNode(num);
                st.push({temp1->left,cnt});
                continue;
            }
            while(!st.empty() && st.top().second>=cnt){
                st.pop();
            }
            TreeNode *temp=st.top().first;
            temp->right=new TreeNode(num);
            st.push({temp->right,cnt});


            

        }
        return root;
        

    }
};