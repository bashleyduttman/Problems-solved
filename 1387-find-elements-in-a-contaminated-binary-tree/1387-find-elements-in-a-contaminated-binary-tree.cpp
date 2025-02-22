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
class FindElements {
public:
    unordered_set<int>st;
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
       
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int value=q.front().second;
            q.pop();
            st.insert(value);
            if(node->left){
                q.push({node->left,(value*2)+1});
            }
            if(node->right){
                q.push({node->right,(value*2)+2});
            }
        }
        

    }
    
    bool find(int target) {
        if(st.find(target)!=st.end()){
            return true;
        }
        return false;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */