class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<vector<int>> adj1(k+1),adj2(k+1);
        vector<vector<int>> mat(k,vector<int>(k,0));
        vector<int>indegree1(k+1,0),indegree2(k+1,0);
        for(int i=0;i<row.size();i++){
            adj1[row[i][0]].push_back(row[i][1]);
            indegree1[row[i][1]]++;
        }
        for(int i=0;i<col.size();i++){
            adj2[col[i][0]].push_back(col[i][1]);
            indegree2[col[i][1]]++;
        }
        vector<int>row_st=toposort(adj1,indegree1,k);
        vector<int>col_st=toposort(adj2,indegree2,k);
        if(row_st[0]==INT_MAX || col_st[0]==INT_MAX) return {};
        int col_ind=0,row_ind=0;
        unordered_map<int,pair<int,int>>mpp;
        for(int i=0;i<col_st.size();i++)  {         
            int node=col_st[i];

             cout<<node<<' ';
            
            mpp[node]={row_ind,col_ind};
            col_ind++;
            
        }
        int rowI=0;
       for(int i=0;i<row_st.size();i++){
            int node=row_st[i];
            int colI=mpp[node].second;
            mat[rowI++][colI]=node;
        }
        return mat;
        
        
        
    }
    vector<int> toposort(vector<vector<int>>adj,vector<int> indegree,int k){
        queue<int>q;
        vector<int>arr;
        for(int i=1;i<k+1;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();q.pop();
            arr.push_back(node);
            
            k--;
            for(int i=0;i<adj[node].size();i++){
                if(--indegree[adj[node][i]]==0){
                    
                    q.push(adj[node][i]);
                }
            }
        }
        if(k!=0) return {INT_MAX};
        return arr;

    }
    
};