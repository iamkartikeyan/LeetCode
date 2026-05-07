class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {
        int i = 0;
        int numssize = nums.size();
        int j = i ; // j should be equal to i from middle pointer 
        int k = numssize - 1;
        while(j <= k){
            if (nums[j] == 0){
                swap(nums[i], nums[j]);
                i++;
                j++; //we need to increase this j++ its compulsory 
            }
            else if (nums[j]== 1){
                j++;
            }
            else{
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }
};

