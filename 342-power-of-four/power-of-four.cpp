class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        
        double log4n = log2(n) / 2;
        return log4n == floor(log4n);
    }
};