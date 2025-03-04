class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long operations = 0;
        int n = nums.size();
        int prev = nums[n - 1]; 

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] > prev) { 
                int k = (nums[i] + prev - 1) / prev; 
                operations += k - 1; 
                prev = nums[i] / k; 
            } else {
                prev = nums[i]; 
            }
        }

        return operations;
    }
};
