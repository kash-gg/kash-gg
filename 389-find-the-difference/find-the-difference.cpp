class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> a;
        for(char c : s){
            a[c]++;
        }

        for (char c : t) {
            a[c]--;
            if (a[c] < 0) {
                return c;      
            }
        }
        return 0;
    }
};