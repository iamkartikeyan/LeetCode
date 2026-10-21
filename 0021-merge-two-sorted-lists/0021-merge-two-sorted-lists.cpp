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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int temp1 = 0; 
        int temp2 = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;
        while( list1 != nullptr || list2 != nullptr){

            if (list1 != nullptr){
                temp1 = list1 -> val;
            }
            else {
                temp1 = INT_MAX;
            }


            if (list2 != nullptr){
                temp2 = list2 -> val;
            }
            else {
                temp2 = INT_MAX;
            }


            if (temp1 >= temp2){
                ans -> next =  new ListNode(temp2);
                list2 = list2 -> next;
            }
            else {
                ans -> next =  new ListNode(temp1);
                list1 = list1 -> next;
            }
        ans = ans-> next;
        }
        return dummy -> next;
    }
};