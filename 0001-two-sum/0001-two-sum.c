/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    int j = numsSize - 1; 
    int k; 
    int *arr = (int*)malloc(2 * sizeof(int));
    
    while (i<j){
        for (k = 0; k<j; k++){
            if (nums[k]+nums[j] == target){
                arr[0] = k;
                arr[1] = j;
                *returnSize = 2;
                return arr;
                }
        }
        j--;    
    }
    *returnSize = 0;
    return NULL;
}