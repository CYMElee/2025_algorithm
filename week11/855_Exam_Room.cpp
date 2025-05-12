class ExamRoom {
private:
    int n;
    vector<int> seats; // Stores occupied seat indices in sorted order
    
public:
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if (seats.empty()) {
            seats.push_back(0);
            return 0;
        }
        
        // Find max gap between consecutive seats
        int maxGap = 0, maxLeft = -1, maxRight = -1;
        int pos = 0;
        
        // Check gap before first seat
        if (seats[0] > 0) {
            maxGap = seats[0];
            maxLeft = -1;
            maxRight = seats[0];
            pos = 0;
        }
        
        // Check gaps between consecutive seats
        for (int i = 1; i < seats.size(); i++) {
            int gap = (seats[i] - seats[i-1]) / 2;
            if (gap > maxGap) {
                maxGap = gap;
                maxLeft = seats[i-1];
                maxRight = seats[i];
                pos = seats[i-1] + gap;
            }
        }
        
        // Check gap after last seat
        if (n - 1 - seats.back() > maxGap) {
            maxGap = n - 1 - seats.back();
            maxLeft = seats.back();
            maxRight = n;
            pos = n - 1;
        }
        
        // Insert new seat in sorted order
        auto it = lower_bound(seats.begin(), seats.end(), pos);
        seats.insert(it, pos);
        return pos;
    }
    
    void leave(int p) {
        // Remove seat p from seats
        auto it = lower_bound(seats.begin(), seats.end(), p);
        seats.erase(it);
    }
};