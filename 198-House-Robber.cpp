class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        //memoization -> return maximum_rob(nums.size()-1,nums,dp);
        //tabulation
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int pick;
            if(i>1){
                pick=nums[i]+dp[i-2];
            }
            else{
                pick=nums[i];
            }
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[nums.size()-1];

    }
    //memoization
    // int maximum_rob(int ind,vector<int> &nums,vector<int> &dp){
    //     if(ind==0){
    //         return nums[ind];
    //     }
    //     if(ind<0){
    //         return 0;
    //     }
    //     if(dp[ind]!=-1){
    //         return dp[ind];
    //     }
    //     int pick=maximum_rob(ind-2,nums,dp)+nums[ind];
    //     int notpick=maximum_rob(ind-1,nums,dp);
    //     return dp[ind]=max(pick,notpick);
    // }
};