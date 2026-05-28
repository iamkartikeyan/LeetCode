// class Solution {
// public:

//     void paranth(int left, int right, int n , vector<string> &ans ,string temp ){
//         if ((left == n) && (right == n)){
//             ans.push_back(temp);
//             return;
//         }

//         if ((right < left) && right < n){
            
//             temp.push_back(')');
//             paranth(left, right+1, n, ans, temp);
//         }
        
//         if (left < n){
//             temp.pop_back();
//             temp.push_back('(');

//             paranth(left + 1, right, n, ans, temp);
//         }
        
//     }
//     vector<string> generateParenthesis(int n) {
//         int left ;
//         int right;
//         string temp;
//         vector<string> ans;
//         paranth(0, 0, n, ans, temp);
//         return ans;
//     }
// };

class Solution {
public:

    void paranth(int left, int right, int n,
             vector<string> &ans, string temp) {

        if (left == n && right == n) {
            ans.push_back(temp);
            return;
        }

        if (right < left && right < n) {
            string temp1 = temp;
            temp1.push_back(')');
            paranth(left, right + 1, n, ans, temp1);
        }

        if (left < n) {
            string temp2 = temp;
            temp2.push_back('(');
            paranth(left + 1, right, n, ans, temp2);
        }
    }

    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        paranth(0, 0, n, ans, temp);
        return ans;
    }
};