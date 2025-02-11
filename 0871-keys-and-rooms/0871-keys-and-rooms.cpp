class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        while (!q.empty()) {
            int room = q.front();
            q.pop();
            visited[room] = true;
            for (int i = 0; i < rooms[room].size(); i++) {

                if (!visited[rooms[room][i]]) {
                    visited[rooms[room][i]] = true;
                    q.push(rooms[room][i]);
                }
            }
        }
        for(int i=0;i<visited.size();i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};