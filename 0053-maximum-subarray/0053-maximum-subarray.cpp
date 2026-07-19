class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        int count = 0;
        for (int i  = 0 ; i <nums.size(); i++){
            if (nums[i] > max){
                max = nums[i];
            }
            count += nums[i];
            if (count > 0){
                if (count > max){
                    max = count;
                }
            }
            else {
                count = 0;
            }
            }
        return max;
    }
};