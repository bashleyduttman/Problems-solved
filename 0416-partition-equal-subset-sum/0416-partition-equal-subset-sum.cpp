class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int it:nums){
            total+=it;
        }
        if(total%2==1)return false;
        int tar=total/2;
        vector<bool>dp(tar+1,false);
        dp[0]=true;
        for(int i=0;i<nums.size();i++){
            for(int j=tar;j>=nums[i];j--){
                dp[j]=dp[j-nums[i]]||dp[j];
            }
        }
        return dp[tar];
    }
};