class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        queue<pair<int, int>> q; 
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

      
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                auto [node, mask] = q.front(); q.pop();

                if (mask == (1 << n) - 1)
                    return steps;

                for (int nei : graph[node]) {
                    int next_mask = mask | (1 << nei);
                    if (!visited[nei][next_mask]) {
                        visited[nei][next_mask] = true;
                        q.push({nei, next_mask});
                    }
                }
            }
            ++steps;
        }

        return -1; 
    }
};