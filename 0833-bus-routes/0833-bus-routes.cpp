class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0; // If already at the target

        unordered_map<int, vector<int>> stopToRoutes; // Mapping from stop to bus routes
        int n = routes.size();

       
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<pair<int, int>> q; 
        unordered_set<int> visitedRoutes; 
        unordered_set<int> visitedStops; 

        
        for (int route : stopToRoutes[source]) {
            q.push({route, 1}); 
            visitedRoutes.insert(route);
        }

        while (!q.empty()) {
            int route = q.front().first;
            int busCount = q.front().second;
            q.pop();

            
            for (int stop : routes[route]) {
                if (stop == target) return busCount; 
                if (visitedStops.find(stop) == visitedStops.end()) {
                    visitedStops.insert(stop);

                    for (int nextRoute : stopToRoutes[stop]) {
                        if (visitedRoutes.find(nextRoute) == visitedRoutes.end()) {
                            q.push({nextRoute, busCount + 1});
                            visitedRoutes.insert(nextRoute);
                        }
                    }
                }
            }
        }

        return -1; 
    }
};
