class Solution {
public:

    set<vector<int>> s;
    void helper(vector<vector<int>> &ans, int i , vector<int>& candidates, int target, vector<int> array ){
        if(target < 0 || i == candidates.size()) {
            return;
        }

        if (target == 0){
            if (s.find(array) == s.end()){
            ans.push_back({array});
            s.insert(array);
            return;
            }
        }
        array.push_back(candidates[i]);
        helper(ans, i+1, candidates, target - candidates[i], array);
        helper(ans, i, candidates, target - candidates[i], array);
        array.pop_back();
        helper(ans, i + 1, candidates, target , array);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> array;
        helper(ans ,0 , candidates, target, array );
        return ans;
    }
};