class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> adj[isConnected.size()];
        vector<int> vis(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adj);
            }
        }
        return cnt;
    }
    void dfs(int i,vector<int> &vis,vector<int> adj[]){
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }
    }
};