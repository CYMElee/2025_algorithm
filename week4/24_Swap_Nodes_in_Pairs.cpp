class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If list is empty or has only one node, return as is
        if (!head || !head->next) {
            return head;
        }
        
        // Create a dummy node to handle the head swap easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        
        // Iterate while there are at least 2 nodes to swap
        while (current->next && current->next->next) {
            // Store the nodes to swap
            ListNode* first = current->next;
            ListNode* second = current->next->next;
            
            // Perform the swap
            first->next = second->next;
            second->next = first;
            current->next = second;
            
            // Move to next pair
            current = first;
        }
        
        // Get the new head and clean up dummy node
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
