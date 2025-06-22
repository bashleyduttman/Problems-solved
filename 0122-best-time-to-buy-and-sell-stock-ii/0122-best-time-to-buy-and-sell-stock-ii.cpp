class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, INT_MIN)); 
        return maximumProfits(prices, 0, 1, dp); 
    }
    
    int maximumProfits(vector<int>& prices, int ind, int flg, vector<vector<int>>& dp) {
        if (ind >= prices.size()) {
            return 0; 
        }
        if (dp[ind][flg] != INT_MIN) {
            return dp[ind][flg]; 
        }
        
        int profit = 0;
        if (flg) {
         
            int buy = maximumProfits(prices, ind + 1, 0, dp) - prices[ind]; 
            int notBuy = maximumProfits(prices, ind + 1, 1, dp); 
            profit = max(buy, notBuy);
        } else {
          
            int sell = maximumProfits(prices, ind + 1, 1, dp) + prices[ind];  
            int notSell = maximumProfits(prices, ind + 1, 0, dp); 
            profit = max(sell, notSell);
        }
        
        return dp[ind][flg] = profit; 
    }
};
