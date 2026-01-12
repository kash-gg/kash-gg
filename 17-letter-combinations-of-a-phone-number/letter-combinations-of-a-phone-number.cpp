class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return {};
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(digits,0,"",result,mapping);
        return result;
    }
    void helper(string digits, int index, string currentCombination, vector<string>& result, string mapping[]) {

    if (index == digits.length()) {
        result.push_back(currentCombination);
        return; 
    }

    int digit = digits[index] - '0';
    string letters = mapping[digit];

    for (char c : letters) {
       
        helper(digits, index + 1, currentCombination + c, result, mapping);
    }
}

};