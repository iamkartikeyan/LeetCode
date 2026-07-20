class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int maxprofit = INT_MIN;
        int count = INT_MIN;

        for(int i = 1 ; i < prices.size() ; i++){
            
            minprice = min(prices[i-1], minprice);
            int temp = prices[i] - minprice;
            count = max(temp, count);
        }
        if (count < 0){
            return 0;
        }
        else {return count;
        }
    }
};