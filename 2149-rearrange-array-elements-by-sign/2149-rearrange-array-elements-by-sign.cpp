class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        int p = 0; int m = 1;
        for (int i = 0; i < n; i++){
            

            if (nums[i] >= 0){
                ans[p] = nums[i];
                p = p+2;
                cout << nums[i];
            }
        
            else {
                ans[m] = nums[i];
                m = m+2;
                cout << nums[i];
            }
        }

        return ans;
    }
};