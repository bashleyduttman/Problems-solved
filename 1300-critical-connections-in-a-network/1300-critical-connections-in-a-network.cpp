
class Solution {
public:
int time=0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0],v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int> timer(n,0),low(n,INT_MAX);
        vector<bool> vis(n,false);
        vector<vector<int>> bridges;
        dfs(0,-1,adj,timer,low,vis,bridges);
        return bridges;

    }
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<int>&timer,vector<int>&low,vector<bool>&vis,vector<vector<int>>&bridges){
        timer[node]=low[node]=time++;
        vis[node]=true;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]==parent) continue;
            if(vis[adj[node][i]]==false){
                dfs(adj[node][i],node,adj,timer,low,vis,bridges);
                low[node]=min(low[node],low[adj[node][i]]);
                 if(low[adj[node][i]]>timer[node]){
                    bridges.push_back({node,adj[node][i]});
                }
            }
            else{
               
                low[node]=min(low[node],low[adj[node][i]]);
            }
           
        }
        
    }
};