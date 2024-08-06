class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        queue=deque([])
        dup=[]
        for i in range(len(mat)):
            arr=[]
            for j in range(len(mat[i])):
                if mat[i][j]==0:
                    queue.append((i,j,0))
                arr.append(0)
            dup.append(arr)
        visited=set()
        while queue:
            row,col,d=queue.popleft()
            dup[row][col]=d
           

            visited.add((row,col))
            if row+1<len(mat) and (row+1,col) not in visited:
                if mat[row+1][col]==1:
                    queue.append((row+1,col,d+1))
                    visited.add((row+1,col))
            if row-1>=0 and (row-1,col) not in visited:
                if mat[row-1][col]==1:
                    queue.append((row-1,col,d+1))
                    visited.add((row-1,col))
            if col+1<len(mat[row]) and (row,col+1) not in visited:
                if mat[row][col+1]==1:
                    queue.append((row,col+1,d+1))
                    visited.add((row,col+1))
            if col-1>=0 and (row,col-1) not in visited:
                if mat[row][col-1]==1:
                    queue.append((row,col-1,d+1))
                    visited.add((row,col-1))
        return dup
