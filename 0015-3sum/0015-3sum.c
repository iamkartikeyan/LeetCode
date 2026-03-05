

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    // Initialize return values
    *returnSize = 0;
    *returnColumnSizes = NULL;
    
    // Edge case: need at least 3 elements
    if (numsSize < 3) {
        return NULL;
    }
    
    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmp);
    
    // Dynamic array for results
    int capacity = 16;
    int **result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    
    for (int i = 0; i < numsSize - 2; i++) {
        
        // Skip duplicate values for i
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        
        // Early termination: if nums[i] > 0, sum cannot be 0
        if (nums[i] > 0)
            break;
        
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            
            long long sum = (long long)nums[i] + nums[left] + nums[right]; // Use long long to avoid overflow
            
            if (sum == 0) {
                
                // Resize if needed
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                
                // Store the triplet
                result[*returnSize] = malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                
                // Skip duplicates for left and right
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                
                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    
    // If no results, free memory and return NULL
    if (*returnSize == 0) {
        free(result);
        free(*returnColumnSizes);
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    // Shrink to fit actual size (optional optimization)
    result = realloc(result, (*returnSize) * sizeof(int*));
    *returnColumnSizes = realloc(*returnColumnSizes, (*returnSize) * sizeof(int));
    
    return result;
}