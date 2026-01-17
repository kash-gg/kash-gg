class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(char c : columnTitle){
            int a = c -'A' + 1;
            result = result * 26 + a;
        }
        return result;
    }
};