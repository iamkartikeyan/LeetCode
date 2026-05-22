class Solution {
public:
    int addDigits(int num) {
        int ans = num;
        int count = num;
        while (num > 9){  
            count = 0; int last = 0;  
            while (num > 0){
                last = num % 10;
                num = num/10;
                count = count + last;
            }
            num = count;
        }
        return count;
    }
};