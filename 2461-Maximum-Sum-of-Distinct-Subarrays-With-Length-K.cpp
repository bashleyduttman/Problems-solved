class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long l=0,r=0,maxi=0,sum=0;
        unordered_map<int,int> mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp[nums[r]]==2 || (r-l+1)>k){
                sum-=nums[l];
                mpp[nums[l]]--;
                l++;
            }
            sum+=nums[r];
            if((r-l+1)==k){
                maxi=max(sum,maxi);
            }
            r++;
        }
        return maxi;

    }
};