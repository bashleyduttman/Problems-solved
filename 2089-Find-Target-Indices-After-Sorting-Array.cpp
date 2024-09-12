class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> op;
        int l=0,r=nums.size()-1;
        
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(nums[mid]>target){
                
                r=mid-1;
            }
            
            else{
                l=mid+1;
            }
        }
        
        while(r>=0){
            if(nums[r]!=target){
                break;
            }
            op.insert(op.begin(),r--);
        }
        return op;
    }
};