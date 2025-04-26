class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
      
        vector<long long> dp(n + 1, INT_MAX);
        dp[0] = 0;

  
        for (int i = 0; i < n; ++i) {
            vector<long long> new_dp(n + 1, INT_MAX);
            new_dp[0] = dp[0];
            for (int j = 0; j <= n; ++j) {
                if (dp[j] == INT_MAX) continue; 
          
                new_dp[j] = min(new_dp[j], dp[j]);
            
                int walls_painted = min(n, j + 1 + time[i]);
                new_dp[walls_painted] = min(new_dp[walls_painted], dp[j] + cost[i]);
            }
            dp = new_dp;
        }

        return dp[n];
    }
};