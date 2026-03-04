int countPairs(int* nums, int numsSize, int target) {
    int i = 0;
    int j = numsSize - 1;
    int count = 0;
    int k;

    while (i<j){
        for (k = i; k < j; k++){
            if (nums[k] + nums[j] < target){
            count++;
            }
        }
        j--;
    }
    return count;
}