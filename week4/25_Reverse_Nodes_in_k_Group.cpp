/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: if list is empty or k=1, no reversal needed
        if (!head || k == 1) return head;
        
        // Dummy node to handle head easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (head) {
            // Check if there are k nodes remaining
            ListNode* curr = head;
            int count = 0;
            while (curr && count < k) {
                curr = curr->next;
                count++;
            }
            
            // If less than k nodes remain, don't reverse
            if (count < k) break;
            
            // Store next group's starting point
            ListNode* nextGroup = curr;
            ListNode* prevNode = nextGroup;
            curr = head;
            
            // Reverse k nodes
            for (int i = 0; i < k; i++) {
                ListNode* next = curr->next;
                curr->next = prevNode;
                prevNode = curr;
                curr = next;
            }
            
            // Connect with previous group
            ListNode* temp = head;
            head = prevNode;
            prev->next = head;
            prev = temp;
            head = nextGroup;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
