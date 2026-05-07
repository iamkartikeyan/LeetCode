class Solution {
public:

    string reverseStr(string s, int k) {
        int n = s.length();
      for (int i = 0; i < n - 1; i = i + 2*k){
        int left = i;
        int right = min(k + i - 1, n - 1); //always check the condition thats its lat element or not 
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
      }
      return s;
    }
};
    