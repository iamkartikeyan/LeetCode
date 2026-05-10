class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min = 0;
        int max = 0;
        int n = nums.size();
        for (int i = 0 ; i < n; i++){
            if (nums[i]> max){
                min = max;
                max = nums[i];
            }
            else if (nums[i]> min){
                min = nums[i];
            }
        }
        int answer = (min - 1) * (max - 1);
        return answer;
    }
};