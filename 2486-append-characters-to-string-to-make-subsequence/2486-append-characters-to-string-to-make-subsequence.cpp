class Solution {
public:
    int appendCharacters(string s, string t) {
        int count = 0;
        int n = s.length();
        int m = t.length();

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (j < m && s[i] == t[j]) {
                count++;
                j++;
            }
        }

        int answer = m - count;
        return answer;
    }
};