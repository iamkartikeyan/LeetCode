void reverseString(char* s, int sSize) {
    int start = 0;
    int last = sSize - 1;
    while(start<last){
        int temp;
        temp = s[start];
        s[start] = s[last];
        s[last] = temp;
        start++;
        last--;        
    }
}