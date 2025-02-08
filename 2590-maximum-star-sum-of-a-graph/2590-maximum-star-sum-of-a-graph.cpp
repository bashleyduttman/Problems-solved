class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        int maxi=INT_MIN;
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,vals[i]+total(i,adj,k,vals,n));

        }
        return maxi==INT_MIN?-1:maxi;
    }
    int total(int node,vector<vector<int>>&adj,int k,vector<int>&vals,int n){
        priority_queue<int> pq;
       
        int sum=0;
       
        for(int i=0;i<adj[node].size();i++){
            int val=adj[node][i];
            pq.push(vals[val]);
        }
        
        while(!pq.empty() && k--){
            if(pq.top()>0) sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};