class Solution {
public:
    void pow(double x, long long &N, double &value ){
        if ( N == 0 ){
            return;
        }
        
        if (N % 2 == 0){
            x = x * x;
            N = N/2;
            pow(x, N, value);
            
        }
        else{
            N = N -1;
            value = value * x;
            pow(x, N, value);
            cout << N;
        }
    }
    double myPow(double x, int n) {
        double value = 1; 
        long long N = n;
        if( n < 0){
            x = 1.0000/x;
            N = -N;
        }
        pow( x, N , value);
        return value;
    }
};