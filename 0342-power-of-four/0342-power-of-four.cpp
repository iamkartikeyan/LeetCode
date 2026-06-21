class Solution {
public:
    bool isPowerOfFour(int n) {
        if ( n == 1){
            return true;
        }
        if ( n == 0 || n <0){
            return false;
        }
        if (n%4 != 0 ){
            cout << "rem " << n;
            return false ;
            
        }
        cout << "hi";
        n = n /4;
        cout << n;
       return isPowerOfFour(n);
        // return true;
    }
};