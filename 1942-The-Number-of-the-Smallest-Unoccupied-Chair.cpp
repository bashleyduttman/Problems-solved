class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<int,int>> event;
        for(int i=0;i<times.size();i++){
            event.push_back({times[i][0],i});
            event.push_back({times[i][1],-i-1});
        }
        sort(event.begin(),event.end());
        priority_queue<int,vector<int>,greater<int>> available;
        for(int i=0;i<times.size();i++){
            available.push(i);
        }
        vector<int> chairs_assigned(times.size(),-1);
        
        for(int i=0;i<event.size();i++){
            int p_index=event[i].second;
            if(p_index>=0){
                int chair=available.top();
                chairs_assigned[p_index]=chair;
                available.pop();
                if(p_index==targetFriend){
                    return chair;
                }
            }
            else{
                available.push(chairs_assigned[-p_index-1]);
            }
        }
        return chairs_assigned[targetFriend];
    }
};