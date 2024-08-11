class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return totalchances(coins.size()-1,amount,coins,dp);
}
int totalchances(int ind,int amt,vector<int>& coins,vector<vector<int>>&  dp)
        {
            if (ind<0)
            {
                return 0;
            }
            if (amt==0){
                return 1;

            }
            if(dp[ind][amt]!=-1){
                return dp[ind][amt];
            }
            int pick=0;
            if (coins[ind]<=amt){
                pick=totalchances(ind,amt-coins[ind],coins,dp);
            }
            int notpick=totalchances(ind-1,amt,coins,dp);
            return dp[ind][amt]=pick+notpick;
           
        }
       
        
    };