
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
   int * arr = (int*)malloc((m+n)*sizeof(int));
   int i = m -1;
   int j = n-1;
    int k = m+n-1;
    int temp;
    while ( i >= 0 && j >= 0){
        if (nums2[j] > nums1[i]){
            temp = nums2[j];
            nums2[j] = nums1[k];
            nums1[k] = temp;
            j--;
            k--;
        }
        else {
            temp = nums1[i];
            nums1[i] = nums1[k];
            nums1[k] = temp;
            i--;
            k--;
        }

        }

    while ( j >= 0 ){
        nums1[k] = nums2[j];
        j--;
        k--;
    }
    




 
    
   }
  
