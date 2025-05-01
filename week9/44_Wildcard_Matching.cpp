class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
      
        vector<bool> dp(n + 1, false);
        dp[0] = true; 

     
        for (int j = 0; j < n && p[j] == '*'; ++j) {
            dp[j + 1] = true;
        }

    
        for (int i = 0; i < m; ++i) {
            vector<bool> new_dp(n + 1, false);
            for (int j = 0; j < n; ++j) {
                if (p[j] == '*') {


                    new_dp[j + 1] = new_dp[j] || dp[j + 1];
                } else if (j >= 0 && (p[j] == '?' || s[i] == p[j])) {
                   
                    new_dp[j + 1] = dp[j];
                }
            }
            dp = new_dp; 
        }

        return dp[n];
    }
};
