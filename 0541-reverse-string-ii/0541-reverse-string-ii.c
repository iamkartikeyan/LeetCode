void reverseRange(char *s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

char* reverseStr(char* s, int k) {
    int n = strlen(s);
    for (int i = 0; i < n; i += 2 * k) {
        
        int start = i;
        int end;
        
        if (i + k - 1 < n) {
            end = i + k - 1; 
        } else {
            end = n - 1; 
        }
        reverseRange(s, start, end);
    }
    
    return s;
}