class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        int maxi=0;
    int ele=0;
        vector<int> indegree(n+1,0);
        for(int i=0;i<n-1;i++){
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
            if(maxi<max(indegree[edges[i][0]],indegree[edges[i][1]])){
                if(indegree[edges[i][0]]<indegree[edges[i][1]]){
                    ele=edges[i][1];
                    maxi=indegree[edges[i][0]];
                }
                else{
                    ele=edges[i][0];
                    maxi=indegree[edges[i][1]];
                }
            }
        }
        return ele;

    }
};