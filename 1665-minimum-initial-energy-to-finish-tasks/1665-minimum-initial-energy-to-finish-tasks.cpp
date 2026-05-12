
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks by the difference (minimum - actual) in descending order
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int total_initial_energy = 0;
        int current_energy = 0;

        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];

            // If current energy is less than what's required to start
            if (current_energy < minimum) {
                // Add the specific deficit to our initial starting energy
                total_initial_energy += (minimum - current_energy);
                // Update current energy to the minimum required to proceed
                current_energy = minimum;
            }
            
            // Spend the actual energy
            current_energy -= actual;
        }

        return total_initial_energy;
    }
};