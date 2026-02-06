class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        double a = log2(n) / 2;
        return a == floor(a);
    }
};