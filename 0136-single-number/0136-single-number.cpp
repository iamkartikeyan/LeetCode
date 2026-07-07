class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int large = nums[0];

        for (int i = 0; i < n; i++) {
            large = max(nums[i], large);
        }

        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            if (mpp[nums[i]] == 1) {
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
};