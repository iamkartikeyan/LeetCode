/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
   int *arr = (int*)malloc(numsSize*sizeof(int));

    *returnSize = numsSize;
   int i = 0;
   int j = numsSize - 1;
    int k = numsSize-1;

    while (i <= j){
        if (abs(nums[i]) < abs(nums[j])){
            arr[k] = nums[j]*nums[j];
            j--;
            k--;
        }
        else {arr[k] = nums[i]*nums[i];
            i++;
            k--;
        }
        }
    return arr;
}