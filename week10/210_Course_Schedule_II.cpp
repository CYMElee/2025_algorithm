class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses); 
        vector<int> indegree(numCourses, 0);  


        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }


        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> order;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            order.push_back(curr);

            for (int neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

    
        if (order.size() != numCourses)
            return {};
        return order;
    }
};