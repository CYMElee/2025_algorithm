class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stationToRoutes;
        int n = routes.size();

        
        for (int i = 0; i < n; ++i) {
            for (int station : routes[i]) {
                stationToRoutes[station].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visitedRoutes;
        unordered_set<int> visitedStations;
        q.push(source);
        visitedStations.insert(source);

        int buses = 0;

        while (!q.empty()) {
            int size = q.size();
            ++buses;

            for (int i = 0; i < size; ++i) {
                int currStation = q.front();
                q.pop();

                for (int route : stationToRoutes[currStation]) {
                    if (visitedRoutes.count(route)) continue;
                    visitedRoutes.insert(route);

                    for (int nextStation : routes[route]) {
                        if (nextStation == target) return buses;
                        if (!visitedStations.count(nextStation)) {
                            q.push(nextStation);
                            visitedStations.insert(nextStation);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
