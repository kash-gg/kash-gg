class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char,int> a;
        for(char c : s ){
            a[c]++;

            if(a[c] % 2 == 1) oddCount++;

            else oddCount--;
        }
        if(oddCount > 1) return s.length() - oddCount + 1;
        return s.length();
        
    }
};