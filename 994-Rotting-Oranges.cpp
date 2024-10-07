class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int mini = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        
        // Push all initially rotten oranges to the queue
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    visited[i][j] = 1;  // Mark initially rotten oranges as visited
                }
            }
        }

        // Run BFS to calculate the total time to rot all oranges
        mini = TotalTime(q, grid, visited);
        
        // Check if any fresh oranges remain
        if (check(grid)) {
            return mini;
        }
        return -1;  // Return -1 if there are still fresh oranges left
    }

    // Function to calculate the total time to rot all oranges
    int TotalTime(queue<pair<int, int>>& q, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int minutes = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};  // Four directions
        
        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            bool rottingOccurred = false;  // To track if rotting occurred in this minute

            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                // Check all four neighbors
                for (auto dir : directions) {
                    int nrow = row + dir.first;
                    int ncol = col + dir.second;
                    
                    // If the neighbor is a fresh orange, rot it
                    if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                        ncol < grid[0].size() && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0) {
                        
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;  // Rot the fresh orange
                        rottingOccurred = true;
                    }
                }
            }
            
            // Increment the minutes if any rotting happened in this minute
            if (rottingOccurred) {
                minutes++;
            }
        }

        return minutes;
    }

    // Function to check if there are any fresh oranges left
    bool check(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    return false;  // Found a fresh orange, return false
                }
            }
        }
        return true;  // No fresh oranges left
    }
};
