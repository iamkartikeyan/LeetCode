
class Solution {
private:
    bool possible(const std::vector<int>& bloomDay, int day, int m, int k) {
        int count = 0;
        int noOfB = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count++;
            } else {
                noOfB += (count / k);
                count = 0;
            }
        }
        noOfB += (count / k);

        return noOfB >= m;
    }

public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        // Prevent integer overflow during multiplication
        long long val = 1LL * m * k;
        int n = bloomDay.size();

        if (val > n) return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int low = mini, high = maxi;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1; // Search left space for minimal day
            } else {
                low = mid + 1;  // Need more days
            }
        }

        return low;
    }
};