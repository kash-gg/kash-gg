class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int a = 1; //curr seq len
        int b = 0; //prev seq len
        int maxK =0;
        for(int i =1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                a++;
            }
            else{
                b = a; //yaha se start karega phir
                a = 1; //reset karega agar bada hua toh
            }
            // check both conditions
            maxK = max(maxK, max(a/2, min(a, b)));
        }
        return maxK>=k;
    }
};

