
class Solution {

    unordered_map<int,vector<int>> a;
public:
    Solution(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            a[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int>& b = a[target];
        int c = rand()% b.size();
        return b[c];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */