class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        vector<vector<int>> visited(grid1.size(),vector<int>(grid1[0].size(),-1));
         vector<vector<pair<int,int>>> vec;
         int cnt=0;

        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[i].size();j++){
                if(grid2[i][j]==1&& visited[i][j]==-1){
                    vec.push_back(bfs(i,j,grid2,visited,dir));
                }
            }
        }
        for(int i=0;i<vec.size();i++){
            int flg=1;
            for(int j=0;j<vec[i].size();j++){
                if(grid1[vec[i][j].first][vec[i][j].second]!=1 ){
                    flg=0;
                }
            }
            if(flg){
                cnt++;
            }
        }
        return cnt;

    }
    vector<pair<int,int>> bfs(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &visited,vector<pair<int,int>> &dir){
        vector<pair<int,int>> st;
        queue<pair<int,int>> q;

        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            st.push_back({row,col});
            visited[row][col]=1;

            q.pop();
            for(auto it:dir){
                int nrow=it.first+row;
                int ncol=it.second+col;
                if(nrow>=0 && ncol>=0 && ncol<grid[0].size() && nrow<grid.size() && visited[nrow][ncol]==-1 && grid[nrow][ncol]==1){        
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
        return st;
    }
};