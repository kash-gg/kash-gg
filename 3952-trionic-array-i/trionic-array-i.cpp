class Solution {
public:
    bool isTrionic(vector<int>& nums, int k = 3) {
        
        if(nums[0]>=nums[1])
        return false;
        int a =1;

        int b =0;
        for(int i=1;i<nums.size();i++){
            int c = nums[i] - nums[i - 1];
            if (c == 0)  
                return false;
            else if (c * a < 0) {  
                a *= -1;
                b += 1;
            }
        }
        return b == k-1;
    }
};