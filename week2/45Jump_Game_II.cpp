class Solution {
public:
   
    int helper(vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();
        if (index >= n - 1) {
            return 0;  
        }

        if (dp[index] != -1) {
            return dp[index]; 
        }

        int minJumps = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            int result = helper(nums, index + i, dp);
            if (result != INT_MAX) {
                minJumps = min(minJumps, 1 + result);  
            }
        }

        dp[index] = minJumps;  
        return minJumps;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;  

        vector<int> dp(n, -1); 
        return helper(nums, 0, dp); 
    }
};
