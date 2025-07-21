class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int> temp;
        backtrack(1,n,k,ans,temp);
        return ans;
    }

private:
    void backtrack(int start,int n,int k,vector<vector<int>>& ans,vector<int>& temp){

        for (int i = start; i <= n; i++) {
    temp.push_back(i);                   // Choose number i
    backtrack(i + 1, n, k, ans, temp);    // Recurse with next number
    temp.pop_back();                     // Remove i (backtrack)
}
    if (temp.size() == k) {
    ans.push_back(temp);
    return;
}
    }
};