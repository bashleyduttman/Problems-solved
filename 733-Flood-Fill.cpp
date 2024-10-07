class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(),vector<int>(image[0].size(),0));
        bfs(sr,sc,visited,image,color,image[sr][sc]);
        return image;
    }
    void bfs(int row,int col,vector<vector<int>> & visited,vector<vector<int>> &image,int color,int ins){
        queue<pair<int,int>> q;
        q.push(make_pair(row,col));
        vector<pair<int,int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            image[row][col]=color;
            visited[row][col]=1;
            for(auto it:directions){
                int nrow=row+it.first;
                int ncol=col+it.second;
                if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && visited[nrow][ncol]==0 && image[nrow][ncol]==ins){
                    q.push(make_pair(nrow,ncol));
                    visited[nrow][ncol]=1;
                }
            }
        }
    }
};