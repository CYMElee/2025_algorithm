class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initialize the search range for the eating speed k
        int left = 1; // Minimum possible speed
        int right = *max_element(piles.begin(), piles.end()); // Maximum possible speed
        
        // Binary search to find the minimum speed
        while (left < right) {
            int mid = left + (right - left) / 2; // Middle speed to test
            long long hours = 0; // Use long long to avoid overflow
            
            // Calculate total hours needed at speed mid
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid; // Ceiling of pile/mid
            }
            
            // If hours exceed h, speed is too slow, increase speed
            if (hours > h) {
                left = mid + 1;
            }
            // If hours are within h, try a smaller speed
            else {
                right = mid;
            }
        }
        
        return left; // Minimum speed that works
    }
};