class Solution {
public:
 unordered_map<int,unordered_map<int,int>>dp;

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return ways(nums,0,target,n,0);
    }
    int ways(vector<int>&nums,int ind,int target,int n,int temp){
        if(ind>=n ){
            return temp==target?1:0;
        }
        if(dp[ind].find(temp)!=dp[ind].end()){
            return dp[ind][temp];
        }
        return dp[ind][temp]=ways(nums,ind+1,target,n,temp+nums[ind])+ways(nums,ind+1,target,n,temp-nums[ind]);
    }
};
