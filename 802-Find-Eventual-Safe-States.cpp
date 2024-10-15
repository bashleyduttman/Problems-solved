class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> reversed_graph(graph.size());
        vector<int> indegree(graph.size(),0);
        queue<int> q;
        vector<int> op;
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                reversed_graph[graph[i][j]].push_back(i);
                indegree[i]++;
            }

        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int val=q.front();
            
            op.push_back(val);
            q.pop();
            for(int i=0;i<reversed_graph[val].size();i++){
                indegree[reversed_graph[val][i]]--;
                if(indegree[reversed_graph[val][i]]==0){
                    q.push(reversed_graph[val][i]);
                }
            }
        }
        sort(op.begin(),op.end());
        return op;


        
    }
};