class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return n_ways(n,dp);
        
    }
    int n_ways(int n,vector<int> &dp){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int pick=n_ways(n-1,dp);
        int not_pick=n_ways(n-2,dp);
        return dp[n]=pick+not_pick;

    }
};