class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        iota(parent.begin(), parent.end(), 0);  

        vector<int> cand1, cand2;
        vector<int> actual_parent(n + 1, 0); 

  
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (actual_parent[v] == 0) {
                actual_parent[v] = u;
            } else {
               
                cand1 = {actual_parent[v], v};
                cand2 = {u, v};
                edge[1] = 0; 
            }
        }

       
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (v == 0) continue; 

            int pu = find(parent, u);
            if (pu == v) {
             
                if (cand1.empty()) return edge;
                return cand1;
            }
            parent[v] = pu;
        }

     
        return cand2;
    }

private:
    int find(vector<int>& parent, int u) {
        if (parent[u] != u)
            parent[u] = find(parent, parent[u]);
        return parent[u];
    }
};