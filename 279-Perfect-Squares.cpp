class Solution {
public:
    int numSquares(int n) {
       
        int value=sqrt(n);
         vector<vector<int>> dp(n+1,vector<int>(value+1,-1));
        return minimum_count(n,value,dp);
    }
    long long minimum_count(int n,long long value,vector<vector<int>> &dp){
        if(value==1){
            return n;
        }
        if(n==0){
            return 0;
        }
        if(n<0 || value==0){
            return INT_MAX;
        }
        if(dp[n][value]!=-1){
            return dp[n][value];
        }
        long long pick=minimum_count(n-(value*value),value,dp)+1;
        long long notpick=minimum_count(n,value-1,dp);
        return dp[n][value]=min(pick,notpick);
    }
};