class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int last;
        int val = num;
        while(num > 0){
            last = num % 10;
            if (val%last==0){
                count++;
            }
            num = num/10;
        }
        return count;
    }
};