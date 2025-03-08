class Solution {
public:
    int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
      
        std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });

        int count = 0, p1 = -1, p2 = -1; 

        for (const auto& interval : intervals) {
            int left = interval[0], right = interval[1];

         
            if (left > p2) {
                p1 = right - 1;
                p2 = right;
                count += 2;
            }
         
            else if (left > p1) {
                p1 = p2;
                p2 = right;
                count += 1;
            }
           
        }

        return count;
    }
};
