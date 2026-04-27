class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    vector<vector<int>> dirs = {
        {},
        {2, 3},
        {0, 1},
        {2, 1},
        {3, 1},
        {2, 0},
        {3, 0}
    };

    bool isValid(int a, int b) {
        return (a == 0 && b == 1) || (a == 1 && b == 0) ||
               (a == 2 && b == 3) || (a == 3 && b == 2);
    }

    bool dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& vis) {
        int n = grid.size(), m = grid[0].size();

        if (r == n - 1 && c == m - 1)
            return true;

        vis[r][c] = true;

        for (int d : dirs[grid[r][c]]) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc])
                continue;

            for (int back : dirs[grid[nr][nc]]) {
                if (isValid(d, back)) {
                    if (dfs(nr, nc, grid, vis))
                        return true;
                }
            }
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        return dfs(0, 0, grid, vis);
    }
};