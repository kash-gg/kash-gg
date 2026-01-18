class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> a;
        for(int x : nums){
            a[x]++;
        }
        int maxfreq = 0;
        for(auto it : a){
        maxfreq = max(maxfreq,it.second);
        }
        int totalCount =0;
        for(auto it : a){
        if(it.second == maxfreq){
            totalCount += maxfreq;
        }
        }
        return totalCount;
    }
};