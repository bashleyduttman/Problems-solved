class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        queue<int>q;
        vector<int>dist(n,0);
        vector<bool> visited(n,false);
        vector<int>not_cycle(n,0);
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            indegree[edges[i]]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            not_cycle[node]=1;
            if(--indegree[edges[node]]==0){
                q.push(edges[node]);
            }
        }
        for(int i=0;i<n;i++){
            if(not_cycle[i]==0 && !visited[i]){
                int cnt=0;
                dfs(i,dist,edges,visited,cnt);
            }
        }
        for(int i=0;i<n;i++){
            if(not_cycle[i]==1 && !visited[i]){
                int cnt=1;
                dfs2(i,dist,edges,visited);
            }
        }
        return dist;


    }
    void dfs(int node,vector<int>&dist,vector<int>&edges,vector<bool>&visited,int &cnt){
        if(visited[node]) return ;
        visited[node]=true;
        cnt++;
        dfs(edges[node],dist,edges,visited,cnt);
        dist[node]=cnt;
       

    }
    int dfs2(int node,vector<int>&dist,vector<int>&edges,vector<bool>&visited){
        if(visited[node]) return dist[node];
        visited[node]=true;
       
        return dist[node]=dfs2(edges[node],dist,edges,visited)+1;
       

    }

};