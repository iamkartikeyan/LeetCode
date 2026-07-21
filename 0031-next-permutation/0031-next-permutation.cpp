class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for (int i = nums.size() - 2 ; i >= 0 ; i-- ){
            if(nums[i] < nums[i+1]){
                 index = i;
                 cout << index;
                break;
            }
            
        }
        if (index == -1){
            sort(nums.begin(), nums.end());
            
        }
      // 
        else {int swap_ind = index+1;
        int smallest = nums[index+1];
        for (int j = index+1; j < nums.size(); j++){
            if (nums[j] > nums[index]){
                if (smallest > nums[j]);
                 swap_ind = j;
            }
        }
      // 
        swap(nums[index], nums[swap_ind]);
        sort(nums.begin() + index + 1, nums.end());
    }
    }
};