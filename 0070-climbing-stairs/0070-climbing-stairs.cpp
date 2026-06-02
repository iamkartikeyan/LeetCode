class Solution {
public:
    int climbStairs(int n) {
        // Handle base cases directly to avoid loop overhead or out-of-bound errors
        if (n <= 2) {
            return n;
        }
        
        int prev2 = 1; // Represents ways to reach step 1
        int prev1 = 2; // Represents ways to reach step 2
        int current = 0;
        
        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};