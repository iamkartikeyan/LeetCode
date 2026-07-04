class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int temp = 0;
        int n = nums.size();
        for (int i = 0 ; i < n ; i++){
            if (nums[i] == 1){
                temp++;
            }
            else {
                if ( temp >= ans){
                    ans = temp;
                }
                temp = 0;

            }
        }
        if (temp > ans){
            return temp;
        }
        return ans;
    }
};