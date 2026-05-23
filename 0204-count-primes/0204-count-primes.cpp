class Solution {
public:
    int countPrimes(int n) {

        vector<bool> prime(n, true);

        if (n <= 2){
            return 0;
        }

        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i * i < n; i++){

            if (prime[i]){

                for (int j = i * i; j < n; j = j + i){
                    prime[j] = false;
                }
            }
        }

        int sum = 0;

        for (int i = 2; i < n; i++){

            if (prime[i]){
                sum++;
            }
        }

        return sum;
    }
};