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
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to the head of the list.
        // This simplifies handling cases where the actual head needs to be removed.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy; // prev always points to the node *before* curr

        while (curr != nullptr) {
            if (curr->val == val) {
                // If curr's value matches val, bypass curr.
                // prev's next pointer should skip curr and point to curr's next.
                prev->next = curr->next;
                // Move curr to the next node (which is now prev->next).
                ListNode* nodeToDelete = curr;
                curr = curr->next;
                delete nodeToDelete; // Optional: free memory
            } else {
                // If curr's value does not match val, move both pointers forward.
                prev = curr;
                curr = curr->next;
            }
        }
        
        // The actual head of the modified list is dummy->next.
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
    }
};