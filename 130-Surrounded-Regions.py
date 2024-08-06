class Solution:
    def solve(self, board: List[List[str]]) -> None:
        queue=deque([])
        for i in range(len(board)):
            for j in range(len(board[i])):
                if (i==0 or j==0 or i==len(board)-1 or j==len(board[i])-1) and board[i][j]=='O':
                    queue.append((i,j))
        values=[(0,1),(1,0),(-1,0),(0,-1)]
        visited=set()
        while queue:
            row,col=queue.popleft()
            board[row][col]=1
           
            visited.add((row,col))
            for val in values:
                r=row+val[0]
                c=col+val[1]
                if r>=0 and r<len(board) and c>=0 and c<len(board[r]):
                    if board[r][c]=='O':
                        queue.append((r,c))
                        visited.add((r,c))
        
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j]==1:
                    board[i][j]='O'
                elif board[i][j]=='O':
                    board[i][j]='X'


        
        