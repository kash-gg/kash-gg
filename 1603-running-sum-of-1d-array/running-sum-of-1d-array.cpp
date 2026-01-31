class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        vector<int> a;
        for(auto num :nums){
            sum += num;
            a.push_back(sum);
        }
        return a;
    }
};