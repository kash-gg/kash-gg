class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int leftpro = 1;
        for(int i =0;i< nums.size(); i++){
            result[i] = leftpro;
            leftpro = leftpro * nums[i];
        }
        int rightpro = 1;
        for(int i = nums.size() - 1;i >=0 ; i--){
            result[i] *= rightpro;
            rightpro *= nums[i];
        }
        return result;
    }
};