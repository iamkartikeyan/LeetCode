class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int nums = candyType.size();
        int candysize = nums/2;
        unordered_set<int> array;
        int temp = 0;
        for (int i = 0; i < nums; i++){
            if (array.count(candyType[i])){
                continue;
            } 
            else {
                array.insert(candyType[i]);
                temp++;
            }
        }
        return min(temp,candysize);
    }
};