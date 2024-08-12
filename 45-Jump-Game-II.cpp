class Solution {
public:
    int jump(vector<int>& nums) {

        vector<int> dp(nums.size()+1,-1);
        return total(0,nums.size()-1,nums,dp);
        
    }
    int total(int ind,int n,vector<int> & nums,vector<int> & dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int maxJump = min(ind + nums[ind], n);
        int mini=555555555;
        for(int i=ind+1;i<=nums[ind]+ind;i++){
           mini=min(mini,total(i,n,nums,dp)+1);
        }
        return dp[ind]=mini;
        
    }
};