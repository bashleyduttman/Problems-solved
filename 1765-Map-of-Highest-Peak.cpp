class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> duplicate=isWater;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(isWater.size(),vector<int>(isWater[0].size(),-1));
        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(duplicate[i][j]==1){
                    duplicate[i][j]=0;
                    q.push({i,j});
                }
                else{
                    duplicate[i][j]=INT_MAX;
                }
            }
        }
        vector<pair<int,int>> dir={{0,1},{-1,0},{1,0},{0,-1}};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(visited[row][col]==1){
                continue;
            }
            visited[row][col]=1;
            
            for(auto it:dir){
                int nrow=row+it.first;
                int ncol=col+it.second;
                if(nrow>=0 && ncol>=0 && nrow<isWater.size() && ncol<isWater[0].size() && visited[nrow][ncol]==-1){
                    duplicate[nrow][ncol]=min(duplicate[nrow][ncol],duplicate[row][col]+1);
                    q.push({nrow,ncol});
                }
            }

        }
        return duplicate;
       
        
    }
};