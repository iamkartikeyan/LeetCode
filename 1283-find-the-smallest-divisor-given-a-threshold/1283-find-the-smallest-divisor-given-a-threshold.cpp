class Solution {
public:

    int sumbydiv(vector<int>& nums, int threshold, int value){
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            sum = sum + ceil((double)nums[i]/(double)(value));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while(low<=high){
            int mid = (low + high)/2;
            if (sumbydiv(nums, threshold, mid) <= threshold){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;

    }
};