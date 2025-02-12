class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int mini=INT_MAX;
        for(int i=0;i<c;i++){
            mini=min(mini,dfs(grid,0,i,r,c,moveCost,dp));
        }
        return mini;
    }
    int dfs(vector<vector<int>>&grid,int row,int col,int r,int c,vector<vector<int>>&cost,vector<vector<int>>&dp){
        if(row==r-1) return grid[row][col];
        int mini=INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];
        for(int i=0;i<c;i++){
            mini=min(mini,dfs(grid,row+1,i,r,c,cost,dp)+cost[grid[row][col]][i]+grid[row][col]);
        }
        
        return dp[row][col]=mini;
    }
};