void sortColors(int* nums, int numsSize) {
    int start = 0;
    int end = numsSize - 1;
    int i = 0;
    while ( i <= end){
        if (nums[i] > 1){
            int temp = nums[i];
            nums[i] = nums[end];
            nums[end] = temp;

            end = end - 1;
        }

        else if ( nums[i] < 1){
            int temp = nums[i];
            nums[i] = nums[start];
            nums[start] = temp;

            start = start + 1;
            i = i + 1;
        } 

        else {
            i = i + 1;
        }   
        }
    }
