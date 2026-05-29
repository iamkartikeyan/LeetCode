class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int min_val = INT_MAX;
        for (int i = 0; i < n ; i++){
            
            int j = 0;
            int temp = 0;
            while (nums[i] > 0){
                temp = temp + nums[i]%10;
                nums[i] = nums[i]/10;
            }
            min_val = min(min_val, temp);
        }
        return min_val;
    }
};