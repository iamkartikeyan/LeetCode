int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    int j = numsSize - 1;
    int *arr = (int*)malloc(2 * sizeof(int));

    while (i < j){
        if (nums[i]+ nums[j] < target){
            i++;
        }
        else if (nums[i] + nums[j] > target){
            j--;
        }
        else {
            arr[0] = i+1;
            arr[1] = j+1;
            *returnSize = 2;
            return arr;
        }
    }
    *returnSize = 0;
    return NULL;
}