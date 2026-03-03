class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size());
        vector<pair<int,int>> a;
        for(int i =0;i<score.size();i++){
            a.push_back({score[i],i});
        }
        sort(a.rbegin(), a.rend());

        for(int i =0;i<score.size();i++){
         
            int j = a[i].second;
            if(i == 0)
            {
                result[j] = "Gold Medal";
            }
            else if(i == 1)
            {
                result[j] = "Silver Medal";
            }
            else if(i == 2)
            {
                result[j] = "Bronze Medal";
            }
            else
                result[j] = to_string(i + 1);
        }
        return result; 
    }
};