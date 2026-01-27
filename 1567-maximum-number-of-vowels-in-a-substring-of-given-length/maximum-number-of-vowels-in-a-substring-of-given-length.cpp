class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        for(int i = 0;i < k;i++){
            if(isVowel (s[i])) count ++;
        }
        int a = count;

        for(int i = k ;i< s.length();i++){
            if(isVowel(s[i-k])) count --;
            if(isVowel(s[i])) count ++;
            a = max(a, count);
        }
        return a;
        
    }

    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};