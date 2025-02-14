class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>indegree(n,0);
        long long sum=0;
        for(int i=0;i<roads.size();i++){
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;

        }
        sort(indegree.begin(),indegree.end(),greater<long long>());
        for(int i=0;i<indegree.size();i++){
            sum+=indegree[i]*n;
            n--;
        }
        return sum;
    }
};