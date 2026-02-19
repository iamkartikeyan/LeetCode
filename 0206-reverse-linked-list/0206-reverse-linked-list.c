/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* second = NULL;

    while (curr != NULL) {
        second = curr->next;   // Store next node
        curr->next = prev;   // Reverse pointer
        prev = curr;         // Move prev forward
        curr = second;         // Move curr forward
    }

    return prev;  // New head
}




