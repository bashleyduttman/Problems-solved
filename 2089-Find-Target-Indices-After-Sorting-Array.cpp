class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> op;
        int l=0,r=nums.size()-1;
        
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(nums[mid]<target){
                l=mid+1;
            }         
            else{
                r=mid-1;
            }
        }   
        while(l<nums.size()){
            if(nums[l]!=target){
                break;
            }
            op.push_back(l++);
        }
        return op;
    }
};