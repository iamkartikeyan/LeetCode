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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ( head == NULL){
            return NULL;
        }
        if(head -> next == NULL){
            return NULL;
        }
       ListNode* curr = head;
        int count = 0;
        while ( curr != NULL ){
            curr = curr -> next;
            count++;
        }
        int N = count - n + 1;
        cout << count << " ";
        cout << n << "  ";
        cout << N;
        
    ListNode* temp = head;
    for ( int i = 1 ; i < N-1 ; i++ ){
        temp = temp -> next;
    }
    if (N== 1) {
        head = head -> next;
    }
    else {temp -> next = temp -> next -> next;
    }
    return head;
    }
    
};