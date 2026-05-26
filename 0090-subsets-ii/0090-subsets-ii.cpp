class Solution {
public:
    vector<vector<int>> result;
    void subset(int i , vector<int> &nums, vector<int> &temp){
        if (i == nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        subset(i+1, nums, temp);
        int j = i ;
        while(j + 1 < nums.size() && nums[j]==nums[j+1]){
            j++;
        }
        temp.pop_back();
        subset(j+1, nums, temp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        subset(0, nums, temp);
        return result;
    }
};