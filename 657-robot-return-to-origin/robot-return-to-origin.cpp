class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char , int> a;
        for(auto c : moves){
            a[c]++;
        }
        return a['U'] == a['D'] && a['L'] == a['R'];
    }
};