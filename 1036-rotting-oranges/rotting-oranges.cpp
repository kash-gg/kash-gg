class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> a;
        int fresh = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) a.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!a.empty() && fresh > 0) {
            int size = a.size();
            minutes++; 

            while (size--) {
                pair<int, int> curr = a.front();
                a.pop();

                for (auto d : directions) {
                    int nx = curr.first + d.first;  
                    int ny = curr.second + d.second;

                    if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2; 
                        fresh--;          
                        a.push({nx, ny}); 
                    }
                }
            }
        }

        return (fresh == 0) ? minutes : -1;
    }
};