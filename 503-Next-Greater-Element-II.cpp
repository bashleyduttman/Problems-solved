class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> op;
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     nums.push_back(nums[i]);
        // }
        
        stack<int> st;
        for(int i=2*nums.size()-1;i>=0;i--){
            int flg=1;
            while(!st.empty()){
                if(st.top()>nums[i%nums.size()]){
                    flg=0;
                    op.push_back(st.top());
                    break;
                }
               
                st.pop();   
            }
            if(flg){
                op.push_back(-1);
            }
           st.push(nums[i%nums.size()]); 
        }
      
        

    reverse(op.begin(),op.end());
    vector<int> newop(op.begin(),op.begin()+n);

        return newop;
    }
};