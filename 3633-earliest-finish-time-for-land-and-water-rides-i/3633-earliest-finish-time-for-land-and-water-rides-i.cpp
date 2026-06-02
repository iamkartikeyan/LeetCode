class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        int minL = 2e9; // INT_MAX की जगह डायरेक्ट बड़ी वैल्यू
        int minW = 2e9;
        int minTotalTime = 2e9;
        
        for (int i = 0; i < n; ++i) {
            minL = min(minL, landStartTime[i] + landDuration[i]);
        }
        
        for (int j = 0; j < m; ++j) {
            minW = min(minW, waterStartTime[j] + waterDuration[j]);
        }
        
        for (int j = 0; j < m; ++j) {
            int finishTime = max(minL, waterStartTime[j]) + waterDuration[j];
            minTotalTime = min(minTotalTime, finishTime);
        }
        
        for (int i = 0; i < n; ++i) {
            int finishTime = max(minW, landStartTime[i]) + landDuration[i];
            minTotalTime = min(minTotalTime, finishTime);
        }
        
        return minTotalTime;
    }
};