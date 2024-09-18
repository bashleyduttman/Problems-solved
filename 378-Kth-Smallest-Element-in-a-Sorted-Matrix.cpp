class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int l=matrix[0][0];
        int r=matrix[n-1][n-1];
        while(l<=r){
            int mid=(l+(r-l)/2);
            if(check(matrix,mid)<k){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return l;
    }
    int check(vector<vector<int>> &matrix,int mid){
        int row=0;
        int col=matrix.size()-1;
        int count=0;
        while(row<matrix.size() && col>=0){
            if(matrix[row][col]<=mid){
                count+=col+1;
                row++;
            }
            else{
                col--;
            }
        }
        return count;
    }

};