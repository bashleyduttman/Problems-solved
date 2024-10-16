class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),-1));
        vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && visited[i][j]==-1 ){
                    maxi=max(maxi,bfs(i,j,grid,visited,dirs));
                }
            }
        }
        return maxi;

    }
    int bfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &visited,vector<pair<int,int>>&dirs){
        queue<pair<int,int>> q;
        q.push({row,col});
        int cnt=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            

            q.pop();

            visited[row][col]=1;

            cnt++;
            for(auto it: dirs){
                int nrow=it.first+row;
                int ncol=it.second+col;
                if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && visited[nrow][ncol]==-1 && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
        return cnt;
    }
};