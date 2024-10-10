class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1) && board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            board[row][col]='1';
            q.pop();
            for(auto it:dir){
                int c_row=row+it.first;
                int c_col=col+it.second;
                if(c_row>=0 && c_col>=0 && c_row<board.size() && c_col<board[0].size() && board[c_row][c_col]=='O'){
                    q.push({c_row,c_col});
                }

            }

        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               
                if(board[i][j]=='1'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};