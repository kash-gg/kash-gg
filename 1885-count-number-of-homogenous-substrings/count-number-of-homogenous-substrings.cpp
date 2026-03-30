class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int count = 1;
        int mod = 1e9 + 7;

        for(int i =1;i<s.size();i++){
            if(s[i]== s[i-1]){
                count++;
            }
            else{
                ans += (long long)count * (count + 1) / 2;
                count = 1;
            }
        }
        ans += (long long)count * (count + 1) / 2;

        return ans % mod;
    }
};