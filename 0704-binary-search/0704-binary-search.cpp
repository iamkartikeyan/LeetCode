class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i]== target){
                k = i; 
                break;
            }
        }
        return k;
        }
};