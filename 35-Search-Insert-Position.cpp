class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=nums.size();
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=int((l+r)/2);
            if(nums[mid]<target){
                ans=mid;
                l=mid+1;
            }
            else{
                ans=mid-1;
                r=mid-1;
            }
        }
        return ans+1;
    }
};