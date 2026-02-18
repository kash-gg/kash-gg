class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total =0;
        for(int x : nums){
            total += x;
        }

        if(total%2 != 0) return false;

        int a = total/2;

        vector<bool> b(a + 1, false);
        b[0]= true;

        for(int num : nums){
            for(int s = a; s>=num; s--){
                b[s] = b[s] || b[s - num];
            }
        }
        return b[a];
    }
};