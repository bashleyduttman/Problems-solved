class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid){
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),-1));
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]>0){
                    maxi=max(maxi,bfs(i,j,grid,dir,visited));
                }
            }
        }
        return maxi;
    }
    int bfs(int row,int col,vector<vector<int>> &grid,vector<pair<int,int>> &dir,vector<vector<int>> &visited){
        queue<pair<int,int>> q;
        q.push({row,col});
        int total=0;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            visited[row][col]=1;
            total+=grid[row][col];
            for(auto it:dir){
                int nrow=row+it.first;
                int ncol=col+it.second;
                if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && grid[nrow][ncol]>0 && visited[nrow][ncol]==-1){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
        return total;

    }
};