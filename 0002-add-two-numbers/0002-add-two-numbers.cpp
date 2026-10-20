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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* dummy = new ListNode(0);


        int carry = 0;
        
        ListNode* answer = dummy;
        while ( curr1 != nullptr || curr2 != nullptr || carry != 0){
            int v1 = (curr1 != nullptr) ? curr1 -> val : 0 ;
            int v2 = (curr2 != nullptr) ? curr2 -> val : 0 ;

            int temp = v1 + v2 + carry;
            cout << temp << " ";

            if (curr1 != nullptr){
                curr1 = curr1 -> next; 
            }
            if (curr2 != nullptr){
                curr2 = curr2 -> next;
            }
            

            if( temp >= 10 ){
                carry = 1;
                temp = temp%10;
            }
            else {
                carry = 0;
            }
            answer -> next = new ListNode(temp);
            answer = answer -> next;
        }

        return dummy-> next;
    }
};