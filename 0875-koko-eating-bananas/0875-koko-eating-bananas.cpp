class Solution {
public:

    int findmax(vector<int>& piles){
                int maxi = INT_MIN;
                int n = piles.size();
                for (int i = 0 ; i < n; i++){
                    maxi = max(piles[i], maxi);
                }
                return maxi;
            }
    
    double calculate_hours(vector<int>& piles, int hourly){
        double required_hours = 0;
        int n = piles.size();
        for (int i = 0 ; i < n ; i++)
            required_hours += ceil((double)piles[i] / (double)hourly);
        return required_hours;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; int high = findmax(piles);

        while(low <= high){
            int mid = (low + high )/2;
            double required_hours = calculate_hours(piles, mid);
            if (required_hours <= h){
                high = mid -1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

