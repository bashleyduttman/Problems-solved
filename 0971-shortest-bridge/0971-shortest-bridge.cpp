class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < r; i++) {
            bool flg = false;
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    bfs(i, j,  grid, r, c, q);
                    flg = true;
                    break;
                }
            }
            if (flg)
                break;
        }
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            for (auto it : dirs) {
                int nrow = row + it.first;
                int ncol = col + it.second;
                if (nrow >= 0 && ncol >= 0 && nrow < r && ncol < c &&
                    grid[nrow][ncol] != 2) {
                    if (grid[nrow][ncol] == 1) {
                        return dis;
                    }
                    grid[nrow][ncol] = 2;
                    q.push({{nrow,ncol},{dis+1}});
                }
            }
        }
        return 1;
    }
    void bfs(int ro, int co, vector<vector<int>>& grid, int r, int c,
             queue<pair<pair<int,int>, int>>& qu) {

        queue<pair<int, int>> q;
        q.push({ro, co});
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            qu.push({{row, col}, {0}});
            grid[row][col] = 2;
            q.pop();
            for (auto it : dirs) {
                int nrow = row + it.first;
                int ncol = col + it.second;
                if (nrow >= 0 && ncol >= 0 && ncol < c && nrow < r &&
                    grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};