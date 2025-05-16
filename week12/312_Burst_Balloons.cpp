class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> points(n + 2, 1);
        for (int i = 0; i < n; ++i) {
            points[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int len = 2; len <= n + 1; ++len) {
            for (int left = 0; left <= n + 1 - len; ++left) {
                int right = left + len;
                for (int k = left + 1; k < right; ++k) {
                    dp[left][right] = max(
                        dp[left][right],
                        dp[left][k] + dp[k][right] + points[left] * points[k] * points[right]
                    );
                }
            }
        }

        return dp[0][n + 1];
    }
};