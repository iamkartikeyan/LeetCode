class Solution {
public:
    int tribonacci(int n) {
        // Base cases jo question mein diye hain
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        // Pichle teen numbers ko yaad rakhne ke liye variables
        int a = 0; // T_0
        int b = 1; // T_1
        int c = 1; // T_2
        int next_term = 0;
        
        // T_3 se lekar T_n tak calculate karein
        for (int i = 3; i <= n; i++) {
            next_term = a + b + c; // Agala number = pichle 3 ka sum
            
            // Variables ko ek step aage shift karo (Sliding Window logic)
            a = b;
            b = c;
            c = next_term;
        }
        
        return c;
    }
};