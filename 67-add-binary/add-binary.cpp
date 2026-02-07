class Solution {
public:
    string addBinary(string a, string b) {
        string result ="";
        int i = a.length() -1;
        int j = b.length() -1;

        int carry = 0;

        while (i >= 0 || j >= 0 || carry){

            if(i>=0){
                carry += a[i] -'0';
                i--;
            }

            if(j>=0){
                carry += b[j]-'0';
                j--;
            }

            result += (carry % 2) + '0';
            carry /=2;
        }
        reverse(begin(result), end(result));
        return result;
    }
};