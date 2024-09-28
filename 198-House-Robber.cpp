class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return maximum_rob(nums.size()-1,nums,dp);
    }
    int maximum_rob(int ind,vector<int> &nums,vector<int> &dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pick=maximum_rob(ind-2,nums,dp)+nums[ind];
        int notpick=maximum_rob(ind-1,nums,dp);
        return dp[ind]=max(pick,notpick);
    }
};