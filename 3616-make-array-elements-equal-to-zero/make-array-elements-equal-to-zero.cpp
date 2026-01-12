class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int Lsum = 0;
        for (int x : nums) {
            Lsum +=x; // ye yaha hoga kya oh ha less gooo 👏👏👏🙌🙌 hehe
            if (x == 0) {
              int Rsum = sum - Lsum;
                if (Lsum == Rsum) {
                    count += 2;
                }
                else if(abs(Lsum - Rsum) == 1){
                    count ++;//ab karke dekhte   fuck nhi hua, iska logic bataa dekh jab Lsum != Rsum tab rukkk
                }     
            }
        }
        return count;
    }
};

// //kuch toh galat ho raha dekhna padega acche se
// tere code ke hisab se toh count 0 ya 2 hi ho sakta h, 1 ka kya
// kaha na pehle 2 ka toh ho jaye: okk
// 1 hard hai
