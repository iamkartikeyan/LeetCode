class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(), cost.end(), greater<int>());
        int i = 0;
        int count = 0;
        for( i = 0; i < (cost.size()/3)*3 ; i = i+3){
            int k = cost[i];
            for (int j = i ; j < i + 2; j++){
                count = count + cost[j];
            //     if (cost[j]< k){
            //         k = cost[j];
            //     }
            // } 
            //     count = count - k;   
            }
            
        }
        while ( i < cost.size()){
            count = count + cost[i];
            i++;
        }
        return count ;
    }
};