class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Handle edge cases
        if (lists.empty()) return nullptr;
        
        // Use min-heap to keep track of smallest nodes
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minHeap(cmp);
        
        // Add first node from each list to heap
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }
        
        // If heap is empty, all lists were empty
        if (minHeap.empty()) return nullptr;
        
        // Dummy node to simplify merging
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        // Process nodes from heap
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Add to result
            curr->next = smallest;
            curr = curr->next;
            
            // Add next node from this list to heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};