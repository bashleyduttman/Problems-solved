class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();

        // Min-heap: {cost, {x, y}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Start from (0,0) with 0 cost
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [cost, pos] = pq.top();
            auto [x, y] = pos;
            pq.pop();

            if (x == m - 1 && y == n - 1) {
                return cost;
            }

            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int new_cost = cost + grid[nx][ny];

                    if (new_cost < dist[nx][ny]) {
                        dist[nx][ny] = new_cost;
                        pq.push({new_cost, {nx, ny}});
                    }
                }
            }
        }

        return -1;
    }
};



