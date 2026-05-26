class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        int hash[52] = {0};
        int n = word.size();
        for (int i = 0; i < n; i++){
            if (islower(word[i])){
                hash[word[i] - 'a']++;
            }
            else {
                hash[word[i] - 'A' + 26]++;
            }
        }
        int i = 0;
        int j = 26;
        while ( i <= 25){
            if (hash[i] >= 1 && hash[j] >= 1){
                count++;
            }
            i++;
            j++;
        }
        return count;
    }
};