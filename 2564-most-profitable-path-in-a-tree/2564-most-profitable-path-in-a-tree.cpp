class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int n = edges.size() + 1;
        vector<int> parent(n, -1);
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        parent[0] = -1;
        for (int i = 0; i < edges.size(); i++) {

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> timeBob(n, INT_MAX);
        int cnt = 1;

   
        parent[0] = -1;
        queue<int> qq;
        qq.push(0);
        visited[0] = true;
        while (!qq.empty()) {
            int p = qq.front();
            qq.pop();
            for (int i = 0; i < adj[p].size(); i++) {
                if (!visited[adj[p][i]]) {
                    parent[adj[p][i]] = p;
                    visited[adj[p][i]] = true;
                    qq.push(adj[p][i]);
                }
            }
        }
        fill(visited.begin(), visited.end(), false);
        while (parent[bob] != -1) {
            timeBob[bob] = cnt++;
            bob = parent[bob];
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 1}});
        cnt = 1;
        int maxi = INT_MIN;
        while (!q.empty()) {
            int node = q.front().first;
            visited[node] = true;
            int amt = q.front().second.first;
            cnt = q.front().second.second;
            q.pop();
            if (cnt < timeBob[node]) {
                amt += amount[node];
            } else if (cnt == timeBob[node]) {
                amt += amount[node] / 2;
            }
            bool isLeaf = true;
            for (int i = 0; i < adj[node].size(); i++) {
                if (!visited[adj[node][i]]) {
                    q.push({adj[node][i], {amt, cnt + 1}});
                    isLeaf = false;
                }
            }
            if (isLeaf) {
                maxi = max(maxi, amt);
            }
        }
        return maxi;
    }
};