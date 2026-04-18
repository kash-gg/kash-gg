class Solution {
public:
    int mirrorDistance(int n) {
        int a = n;
        int reverse = 0;
        while(n!=0){
            int digit = n % 10;
            n /= 10;
            reverse = reverse * 10 + digit;
        }
        return abs(a-reverse);
    }
};