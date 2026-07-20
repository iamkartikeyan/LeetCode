class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int count = 0;

        for(int i = 1 ; i < prices.size() ; i++){
            minprice = min(prices[i-1], minprice);
            count = max(prices[i] - minprice, count);
        }
        return count;
        
    }
};