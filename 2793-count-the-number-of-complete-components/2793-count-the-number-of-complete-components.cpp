class Dsu {
public:
    vector<int> size, parent;
    Dsu(int n) {
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findparent(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = findparent(parent[v]);
    }
    void union_connect(int u, int v) {
        int pu = findparent(u);
        int pv = findparent(v);
        if (pu == pv) {
            return;
        }
        if (size[pu] > size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> vec(n);
        vector<int> edgeCount(n, 0);
        Dsu d(n);
        for (int i = 0; i < edges.size(); i++) {
            d.union_connect(edges[i][0], edges[i][1]);
            edgeCount[edges[i][0]]++;
            edgeCount[edges[i][1]]++;
        }
        for (int i = 0; i < n; i++) {
            int pu = d.findparent(i);
            vec[pu].push_back(i);
        }
        int cnt = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].empty())
                continue;
            bool isConnected = true;
            int exp = d.size[i] - 1;
            for (int j = 0; j < vec[i].size(); j++) {

                if (edgeCount[vec[i][j]] != exp) {
                    isConnected = false;
                    break;
                }
            }
            if (isConnected)
                cnt++;
        }
        return cnt;
    }
};