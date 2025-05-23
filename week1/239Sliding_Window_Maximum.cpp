class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty() || k <= 0) return result;
        
     
        deque<int> dq;
        
  
        for (int i = 0; i < nums.size(); i++) {
       
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
      
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
      
            dq.push_back(i);
            
       
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};
