#include <vector>

class Solution {
private:
    void dfs(int r, int c, std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return;
        }

        grid[r][c] = 0;

        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int numEnclaves(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int r = 0; r < m; ++r) {
            if (grid[r][0] == 1) dfs(r, 0, grid);
            if (grid[r][n - 1] == 1) dfs(r, n - 1, grid);
        }

        for (int c = 0; c < n; ++c) {
            if (grid[0][c] == 1) dfs(0, c, grid);
            if (grid[m - 1][c] == 1) dfs(m - 1, c, grid);
        }

        int count = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};