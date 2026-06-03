class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        for(int i = 0; i<landStartTime.size();i++){
            for(int j = 0; j < waterStartTime.size(); j++) {
                int landFinish =landStartTime[i] + landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);
                int finalFinish = waterStart + waterDuration[j];
                ans = min(ans, finalFinish);
                int waterFinish = waterStartTime[j] + waterDuration[j];
int landStart = max(waterFinish, landStartTime[i]);
int finalFinish2 = landStart + landDuration[i];

ans = min(ans, finalFinish2);
            }
        }
        return ans;
    }
};