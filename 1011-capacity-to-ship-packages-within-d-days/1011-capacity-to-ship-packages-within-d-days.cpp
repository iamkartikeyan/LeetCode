class Solution {
public:

    int check(vector<int>& weights, int capacity){
        int n = weights.size();
        int ans = 0; int count = 0;
        for (int i = 0 ; i < n ; i++){
            if (count + weights[i] <= capacity){
                count = count + weights[i];
            }
            else {
                ans++;
                count = weights[i];
            }
        }
        ans++;
        return ans;
    }
    int sum_all(vector<int>& weights){
        int n = weights.size();
        int sum = 0;
        for (int i = 0 ; i < n ; i++){
            sum = sum + weights[i];
        }
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = sum_all(weights);
        while (low <= high){
            int mid = (low + high)/2;
            if (check(weights, mid) <= days){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low ; 
    }
};