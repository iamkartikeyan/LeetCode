class Solution {
public:
    int numberOfSpecialChars(string word) {

        int lower[26] = {0};
        int upper[26] = {0};

        for (char ch : word) {

            if (islower(ch)) {

                int idx = ch - 'a';

                if (upper[idx] == 1) {
                    lower[idx] = -1;
                }

                else if (lower[idx] != -1) {
                    lower[idx] = 1;
                }
            }

            else {

                int idx = ch - 'A';
                
                upper[idx] = 1;
            }
        }

        int count = 0;

        for (int i = 0; i < 26; i++) {

            if (lower[i] == 1 && upper[i] == 1) {
                count++;
            }
        }

        return count;
    }
};