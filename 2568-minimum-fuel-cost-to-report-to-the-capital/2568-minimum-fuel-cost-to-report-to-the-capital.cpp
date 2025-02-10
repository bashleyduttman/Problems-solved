class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1; 
        if (n == 1) return 0; 

        vector<vector<int>> adj(n);
        vector<int> dist(n, -1);
        vector<int> parent(n, -1); 

        for (auto &road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }

        // BFS to calculate distances from node 0 and determine parent nodes
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) { 
                    dist[neighbor] = dist[node] + 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        // Sort nodes based on their distance from node 0 (farthest first)
        vector<int> arr(n);
        iota(arr.begin(), arr.end(), 0);
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return dist[a] > dist[b];
        });

        long long fuel = 0;
        vector<int> representatives(n, 1); 
        for (int i = 0; i < n; ++i) {
            int node = arr[i];
            if (node == 0) continue; 
            int p = parent[node];
            
            fuel += (representatives[node] + seats - 1) / seats;
            representatives[p] += representatives[node];
        }

        return fuel;
    }
};