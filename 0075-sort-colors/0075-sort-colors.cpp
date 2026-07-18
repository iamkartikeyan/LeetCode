class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int i = 0;
        while ( i <= right)
            if (nums[i] == 2){
                swap(nums[i], nums[right]);
                right--;
            }
            else if (nums[i] == 1){
                i++;
            }

            else {
                swap(nums[left], nums[i]);
                left++;
                i++;
            }
        }
    
};