class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int r_size=grid.size();
        int c_size=grid[0].size();
        vector<vector<int>> mark(grid.size(), vector<int>(grid[0].size(), -1));
       vector<vector<vector<int>>> dp(grid.size() + 2, vector<vector<int>>(grid[0].size() + 2, vector<int>(health + 10, -1)));


        return issafe(grid,0,0,r_size,c_size,health,mark,dp);
    }
    int issafe(vector<vector<int>> &grid,int row,int col,int r_size,int c_size,int health,vector<vector<int>> &mark,vector<vector<vector<int>>> &dp){
        if(row>=r_size || col>=c_size || row<0 || col<0 || health<=0 || mark[row][col]!=-1){
            return false;
        }
        if(grid[row][col]==1){
            health-=1;
        }
        if(health<=0){
            return false;
        }
        if(row==r_size-1 && col==c_size-1){
            return true;
        }  
        if(dp[row][col][health]!=-1){
            return dp[row][col][health];
        }      
        
        mark[row][col]=1;
        int up=issafe(grid,row+1,col,r_size,c_size,health,mark,dp);
        int down=issafe(grid,row-1,col,r_size,c_size,health,mark,dp);
        int left=issafe(grid,row,col-1,r_size,c_size,health,mark,dp);
        int right=issafe(grid,row,col+1,r_size,c_size,health,mark,dp);
        mark[row][col]=-1;
        return dp[row][col][health]=up||down||left||right;
    }
};