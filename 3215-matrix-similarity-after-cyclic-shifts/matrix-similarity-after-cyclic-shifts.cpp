class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        k %= m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                int same;

                if (i % 2 == 0) {
                    same = mat[i][(j + k) % m];
                } else {
                    same = mat[i][(j - k + m) % m];
                }
                if (mat[i][j] != same)
                    return false;
            }
        }
        return true;
    }
};