class Solution {
public:
    vector<int> dirX = {-1, 1, 0, 0}; 
    vector<int> dirY = {0, 0, -1, 1}; 

    bool bfs(vector<vector<int>> &grid, int row, int col) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 1; 

        bool isClosed = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dirX[i], nc = c + dirY[i];

              
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                    isClosed = false;
                    continue;
                }

                if (grid[nr][nc] == 0) {
                    grid[nr][nc] = 1; 
                    q.push({nr, nc});
                }
            }
        }

        return isClosed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;

       
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) { 
                    if (bfs(grid, r, c)) {
                        count++; 
                    }
                }
            }
        }

        return count;
    }
};
