class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<bool>visited(n+1,false);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0],v=roads[i][1],wt=roads[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
           
        }
        int mini=INT_MAX;
        dfs(1,adj,mini,visited);
        return mini;
    }
    void dfs(int node,vector<vector<pair<int,int>>>&adj,int &mini,vector<bool>&visited){
        if(visited[node]) return;
        visited[node]=true;
        for(int i=0;i<adj[node].size();i++){
           
            mini=min(mini,adj[node][i].second);
            dfs(adj[node][i].first,adj,mini,visited);
            
        }
        
    }
};