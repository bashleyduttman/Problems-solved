class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(5,INT_MIN));
        dp[0][0]=0;
        for(int k=1;k<=4;k++){
            if(k%2==1)dp[0][k]=-arr[0];
            else dp[0][k]=0;
        }
        for(int i=1;i<=n;i++){
              dp[i][0] = 0; // No transactions
            for(int j=1;j<=4;j++){
            
                int take=INT_MIN;
                if(j%2==1){
                    take=dp[i-1][j-1]-arr[i-1];
                }
                else{
                    take=dp[i-1][j-1]+arr[i-1];
                }
                int notTake=dp[i-1][j];
               dp[i][j]=max(take,notTake);
            }
        }
        
        return dp[n][4];
    }
   
};