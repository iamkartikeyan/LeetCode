bool isPalindrome(char* s) {
    long long int ptr1; long long int ptr2;
    ptr1 = 0;
    ptr2 = strlen(s) - 1;
    while (ptr1 < ptr2){
        if (!isalnum(s[ptr1])) {
            ptr1++;
        }
        else if (!isalnum(s[ptr2])) {
            ptr2--;
        }
        else if (tolower(s[ptr1]) != tolower(s[ptr2])){
            return false;
        }
        else {ptr1++;
        ptr2--;
        }
        }
    return true;
    }