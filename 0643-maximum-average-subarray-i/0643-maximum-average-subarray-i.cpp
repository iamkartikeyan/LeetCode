class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        
        int j = k;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            sum = sum + nums[i];
        }
        double max = sum;

        for (int i = 0; i < n-k; i++){
            sum = sum - nums[i];
            sum = sum + nums[j];
            j++;
            
            if (sum > max){
                max = sum;
            }
        }
        double average = max/k;
        return average;
    }
};