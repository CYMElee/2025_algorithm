class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        
        // Build max heap with bottom-up approach
        for (int i = n / 2 - 1; i >= 0; i--) {
            siftDown(nums, n, i);
        }
        
        // Extract elements and rebuild heap
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            siftDown(nums, i, 0);
        }
        
        return nums;
    }
    
private:
    // Optimized sift down procedure
    inline void siftDown(vector<int>& nums, int n, int i) {
        int maxIndex = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        // Compare both children at once to reduce branch mispredictions
        if (left < n) {
            if (nums[left] > nums[maxIndex]) {
                maxIndex = left;
            }
            if (right < n && nums[right] > nums[maxIndex]) {
                maxIndex = right;
            }
        }
        
        if (maxIndex != i) {
            swap(nums[i], nums[maxIndex]);
            siftDown(nums, n, maxIndex);
        }
    }
};