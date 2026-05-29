class Solution {
public:
    int minElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n ; i++){
            
            int j = 0;
            int temp = 0;
            while (nums[i] > 0){
                temp = temp + nums[i]%10;
                nums[i] = nums[i]/10;
            }
            ans.push_back(temp);
        }
        return *min_element(ans.begin(), ans.end());
    }
};