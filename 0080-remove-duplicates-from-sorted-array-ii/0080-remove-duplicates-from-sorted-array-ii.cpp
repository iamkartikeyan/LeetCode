class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n - 3; ) {
            if (nums[i] == nums[i + 2]) {
                for (int j = i + 2; j <= n - 2; j++) {
                    nums[j] = nums[j + 1];
                }
                n--;
            } else {
                i++;
            }
        }

        return n;
    }
};