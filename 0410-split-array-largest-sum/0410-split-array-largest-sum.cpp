class Solution {
public:

    bool possible (int barrier, vector<int>& nums, int k ){
        int count = 1; int student = 0; int n = nums.size();
        for (int i = 0; i < n ; i++ ){
            if (barrier < nums[i]){
                return false; 
            }
            if (student + nums[i] <= barrier){
                student = student + nums[i];
            }
            else {
                count++;
                student = nums[i];  
            }
        }

        if(count > k ){
            return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = nums[0];
        int high = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            high = high + nums[i];
        }

        while(low <= high){
            int mid = low + (high - low)/2;
                if (possible(mid, nums, k) == true){
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        return low;
        
    }
};