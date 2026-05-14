class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxval = nums[0];
        int minval = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            if (nums[i] > maxval){
                maxval = nums[i];
            }
            if (nums[i] < minval){
                minval = nums[i];
            }
        }
        while (minval > 0){
            
            int temp  = maxval % minval;
            maxval = minval;
            minval = temp; 

        }
        return maxval;
    }
};