class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current = nums;
        backtrack(0, current, result);
        return result;
    }

private:
    void backtrack(int start, vector<int>& nums, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            backtrack(start + 1, nums, result);
            swap(nums[start], nums[i]); 
        }
    }
};