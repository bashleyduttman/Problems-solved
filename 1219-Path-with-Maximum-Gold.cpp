class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int maxi=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]!=0){
                    maxi=max(maxi,maxi_gold(i,j,grid,row,col));
                }
            }
        }
        return maxi;
    }
    int maxi_gold(int row,int col,vector<vector<int>> & grid ,int r_size,int c_size){
        if(row<0 || col<0|| row>=r_size || col>=c_size){
            return 0;
        }
        if(grid[row][col]==0){
            return 0;
        }
        int maxi=0;
        int cg=grid[row][col];
        grid[row][col]=0;
        int bottom=maxi_gold(row+1,col,grid,r_size,c_size);
        int top=maxi_gold(row-1,col,grid,r_size,c_size);
        int left=maxi_gold(row,col-1,grid,r_size,c_size);
        int right=maxi_gold(row,col+1,grid,r_size,c_size);
        maxi=max(maxi,bottom);
        maxi=max(maxi,right);
        maxi=max(maxi,left);
        maxi=max(maxi,top);
        grid[row][col]=cg;
        return maxi+grid[row][col];
    }
};