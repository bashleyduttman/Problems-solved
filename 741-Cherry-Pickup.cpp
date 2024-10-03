class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(n, -1)));
        bool flg = true;
        int result = maximum_pick(0, 0, 0, grid, flg, memo);
        return result < 0 ? 0 : result;
    }

private:
    int maximum_pick(int row1, int col1, int col2, vector<vector<int>>& grid, bool& flg, vector<vector<vector<int>>>& memo) {
        int n = grid.size();
        int row2 = row1 + col1 - col2;  
        if (row1 >= n || row2 >= n || col1 >= n || col2 >= n || 
            grid[row1][col1] == -1 || grid[row2][col2] == -1) {
            return INT_MIN;
        }

      
        if (row1 == n - 1 && col1 == n - 1) {
            flg = false;
            return grid[row1][col1];
        }

     
        if (memo[row1][col1][col2] != -1) {
            return memo[row1][col1][col2];
        }

       
        int result = grid[row1][col1];
        if (col1 != col2) {  
            result += grid[row2][col2];
        }

      
        int maxNext = max({
            maximum_pick(row1, col1 + 1, col2 + 1, grid, flg, memo),  
            maximum_pick(row1 + 1, col1, col2 + 1, grid, flg, memo),  
            maximum_pick(row1, col1 + 1, col2, grid, flg, memo),      
            maximum_pick(row1 + 1, col1, col2, grid, flg, memo)        
        });

        if (maxNext == INT_MIN) {
            result = INT_MIN;
        } else {
            result += maxNext;
        }

        
        return memo[row1][col1][col2] = result;
    }
};