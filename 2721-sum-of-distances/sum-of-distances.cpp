class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> result(nums.size());
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        for (auto& p : mp) {
            vector<int>& v = p.second;
            int m = v.size();

            long long total = 0;
            for (int x : v)
                total += x;

            long long leftSum = 0;

            for (int i = 0; i < m; i++) {
                long long idx = v[i];

                long long left = idx * i - leftSum;

                long long right = (total - leftSum - idx) - idx * (m - i - 1);

                result[idx] = left + right;

                leftSum += idx;
            }
        }
        return result;
    }
};