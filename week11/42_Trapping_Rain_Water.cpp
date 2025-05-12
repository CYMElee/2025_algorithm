class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0; // Need at least 3 bars to trap water
        
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        
        while (left < right) {
            // Update the maximum height seen from left and right
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            
            // Water trapped at current position is determined by the smaller of leftMax and rightMax
            if (leftMax <= rightMax) {
                water += leftMax - height[left];
                left++;
            } else {
                water += rightMax - height[right];
                right--;
            }
        }
        
        return water;
    }
};