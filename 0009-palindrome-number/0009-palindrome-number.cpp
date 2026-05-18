class Solution {
    public:
        bool isPalindrome(int x) {
                // Step 1: Handle edge cases
                        if (x < 0 || (x % 10 == 0 && x != 0))
                                    return false;

                                            int rev = 0;

                                                    // Step 2: Reverse half of the number
                                                            while (x > rev) {
                                                                        rev = rev * 10 + x % 10;
                                                                                    x /= 10;
                                                                                            }

                                                                                                    // Step 3: Check palindrome
                                                                                                            return (x == rev || x == rev / 10);
                                                                                                                }
                                                                                                                };
