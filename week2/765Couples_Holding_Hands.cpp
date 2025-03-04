class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n); 
        int swaps = 0;
        
       
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }
        
        
        for (int i = 0; i < n; i += 2) {
            int person1 = row[i];         
            int person2 = person1 ^ 1;    
            
        
            if (pos[person2] != i + 1) {
                int currentNext = row[i + 1]; 
                int nextPos = i + 1;           
                
               
                row[pos[person2]] = currentNext;
                pos[currentNext] = pos[person2];
                row[nextPos] = person2;
                pos[person2] = nextPos;
                
                swaps++;
            }
        }
        
        return swaps;
    }
};
