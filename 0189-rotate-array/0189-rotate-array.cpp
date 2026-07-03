class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int start = n - k + +1;
        int end = n - 1; 
        k = k %n;
        vector<int> temp;

        for(int i = n-k; i < n ; i++){
            temp.push_back(nums[i]);
        }

        for(int i = n-1; i >= k; i--){
            nums[i] = nums[i - k];
            end--;
        }

        for (int i = 0; i < k ; i++){
            nums[i] = temp[i];
        }
    }
};