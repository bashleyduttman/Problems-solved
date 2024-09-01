class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1;
        int suffix=1;
        vector<int> op(nums.size());
        for(int i=0;i<nums.size();i++){
            op[i]=prefix;
            prefix*=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--){
            op[i]*=suffix;
            suffix*=nums[i];
        }
        return op;
        
    }
};