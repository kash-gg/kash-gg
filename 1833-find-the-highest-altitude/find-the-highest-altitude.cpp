class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int n= gain.size();
        vector<int> prefixSum(n+1);
        prefixSum[0] =0;
        
        for(int i=1; i<=n; i++) {
            prefixSum[i] = prefixSum[i-1] + gain[i-1];
        }
        ans = *max_element(prefixSum.begin(), prefixSum.end());
        return ans;
    }
};
