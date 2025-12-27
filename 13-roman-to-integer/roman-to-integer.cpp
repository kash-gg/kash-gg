class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> a;
        a['I'] = 1;
        a['V'] = 5;
        a['X'] = 10;
        a['L'] = 50;
        a['C'] = 100;
        a['D'] = 500;
        a['M'] = 1000;
        int total = 0;
        int prev = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int curr = a[s[i]];

            if (curr < prev)
                total -= curr;
            else
                total += curr;

            prev = curr;
        }
        return total;
    }
};