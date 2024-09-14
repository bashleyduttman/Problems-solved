class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int col = mat[0].size();
        for (int i = 0; i < mat.size(); i++) {
            int val = findpeak(mat, i, col);
            if (val != -1) {
                return {i, val};
            }
        }
        return {1, 1};
    }
    int findpeak(vector<vector<int>>& mat, int row, int col) {
        int nRows = mat.size();
        if(mat[row].size()==1){
            return 0;
        }
         if (mat[row][0] > mat[row][1]) {
            if (row == 0 || mat[row][0] > mat[row - 1][0]) {
                if (row == nRows - 1 || mat[row][0] > mat[row + 1][0]) {
                    return 0;
                }
            }
        }
        
       
        if (mat[row][col - 1] > mat[row][col - 2]) {
            if (row == 0 || mat[row][col - 1] > mat[row - 1][col - 1]) {
                if (row == nRows - 1 || mat[row][col - 1] > mat[row + 1][col - 1]) {
                    return col - 1;
                }
            }
        }
        int l = 1, r = col - 2;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mat[row][mid] > mat[row][mid + 1] &&
                mat[row][mid] > mat[row][mid - 1] &&(row==nRows-1 || (mat[row + 1][mid] < mat[row][mid])) &&
                (row==0 || (mat[row - 1][mid] < mat[row][mid]))) {
                return mid;
            }
            if (mat[row][mid] < mat[row][mid + 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};