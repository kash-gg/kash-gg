class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count = 0;
        for (int i =0;i<=s.size()-k;i++){
            int sub = stoi(s.substr(i,k));
            if(sub != 0 && num % sub == 0){
                count++;
            }
        }
        return count;
    }
};