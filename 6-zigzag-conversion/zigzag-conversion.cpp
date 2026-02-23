class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length())
            return s;

        string result;

        int cycle = 2 * (numRows - 1);

        for (int r = 0; r < numRows; ++r) {
            for (int j = 0; j + r < s.length(); j += cycle) {
                result += s[j + r];

                int a = j + cycle - r;
                if (r != 0 && r != numRows - 1 && a < s.length()) {
                    result += s[a];
                }
            }
        }

        return result;
    }
};