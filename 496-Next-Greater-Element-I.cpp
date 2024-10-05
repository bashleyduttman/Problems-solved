class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mpp;
        for(int i=nums2.size()-1;i>=0;i--){
            int flg=1;
            while(!st.empty()){
                if(st.top()>nums2[i]){
                    mpp[nums2[i]]=st.top();
                    flg=0;
                    break;
                }
                else{
                   
                    st.pop();
                }
            }
            if (flg){
                mpp[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }
        vector<int> vec;
        for(int i=0;i<nums1.size();i++){
            vec.push_back(mpp[nums1[i]]);
        }
        return vec;

    }
};