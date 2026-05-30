class Solution {
public:

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        int i = 0, j = 0;
       

        for (int k = 0 ; k < m; k++){
            int i = 0;
            int j = k;
            int first = matrix[i][j];
        while(i < n && j < m){
            if (matrix[i][j] != first){
                return false;
            }
            i++;
            j++;
        }
        }

        for (int k = 0 ; k < n; k++){
            int i = k;
            int j = 0;
            int first = matrix[i][j];
        while(i < n && j < m){
            if (matrix[i][j] != first){
                return false;
            }
            i++;
            j++;
        }
        }
        return true;
    }
};