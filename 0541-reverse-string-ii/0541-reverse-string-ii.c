char* reverseStr(char* s, int k) {
    int length = strlen(s);
    
    for (int i = 0; i < length; i += 2 * k) {
        
        int first = i;
        int last = i + k - 1;
        
        if (last >= length) {
            last = length - 1;
        }
        
        while (first < last) {
            char temp = s[first];
            s[first] = s[last];
            s[last] = temp;
            
            first++;
            last--;
        }
    }
    
    return s;
}