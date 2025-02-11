class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        vector<int> output(n);
        for (int i = 0; i < n; i++) {
            output[i] = i; 
        }

        for (const auto& r : richer) {
            adj[r[1]].push_back(r[0]); 
        }

        
        for (int i = 0; i < n; i++) {
            if (output[i] == i) {  
                dfs(i, output, adj, quiet);
            }
        }
        return output;
    }

private:
    int dfs(int node, vector<int>& output, vector<vector<int>>& adj, vector<int>& quiet) {
        if (output[node] != node) return output[node]; 
        int min_person = node;
        for (int neighbor : adj[node]) {
            int candidate = dfs(neighbor, output, adj, quiet); 
            if (quiet[candidate] < quiet[min_person]) {
                min_person = candidate;
            }
        }
        return output[node] = min_person; 
    }
};