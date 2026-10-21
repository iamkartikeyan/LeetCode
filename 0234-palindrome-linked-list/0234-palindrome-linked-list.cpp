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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        vector<int> arr;
        while ( curr != nullptr){
            arr.push_back(curr-> val);
            curr = curr-> next;
        }
        int n = arr.size();

        for (int i = n-1; i >= 0 ; i--){
            int temp = head -> val;
            if (arr[i] != temp ){
                return false;
            }
            head = head-> next;
        }
        return true;
    }
};