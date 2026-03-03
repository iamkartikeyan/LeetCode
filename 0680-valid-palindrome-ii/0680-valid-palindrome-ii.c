bool palindromehelper(char*s, int i, int j){
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;   
    }

bool validPalindrome(char* s) {
   int i = 0;
   int j = strlen(s) - 1;
   while ( i < j){
        if (s[i] != s[j]){
            return palindromehelper(s, i+1, j) || palindromehelper(s, i, j-1);   
            }
        
        i++;
        j--;       
   }
        return true;
    }

