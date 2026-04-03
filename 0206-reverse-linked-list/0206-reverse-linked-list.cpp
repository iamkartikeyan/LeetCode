class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* second = NULL;

        while (curr != NULL) {
            second = curr->next;     // store next
            curr->next = prev;     // reverse link
            prev = curr;           // move prev
            curr = second;           // move curr
        }

        return prev; // new head
    }
};