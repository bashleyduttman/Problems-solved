class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp(nums.size()+1,-1);
        vector<int> dp1(nums.size()+1,-1);
        return max(maximum_rob(0,nums.size()-2,nums,dp),maximum_rob(1,nums.size()-1,nums,dp1));
        
       
    }
     int maximum_rob(int end,int ind,vector<int> &nums,vector<int> &dp){
        if(ind==end){
            return nums[ind];
        }
        if(ind<end){
            return 0;
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }
       
        int pick=maximum_rob(end,ind-2,nums,dp)+nums[ind];
       
        int notpick=maximum_rob(end,ind-1,nums,dp);
        return dp[ind]=max(pick,notpick);
    }
};