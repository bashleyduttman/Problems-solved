class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        if(r==0){
            return nums[0];

        }
        while(l<=r){
            int mid=(l+(r-l)/2);
            cout<<nums[mid]<<'\
';
            if(mid==0 && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid==nums.size()-1 && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if((mid%2==0 && nums[mid+1]!=nums[mid]) || ((mid%2)==1 && nums[mid+1]==nums[mid])){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return 0;
    }
    
};