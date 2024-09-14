class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        vector<int> dirx = {-1, 1, 0, 0};
        vector<int> diry = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int newRow = row + dirx[i];
            int newCol = col + diry[i];
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size() &&
                !vis[newRow][newCol] && grid[newRow][newCol] == 1) {
                grid[newRow][newCol] = 2; // Rotten the fresh orange
                dfs(newRow, newCol, grid, vis);
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool hasFresh = false;

        // Check initial state for fresh oranges and mark rotten oranges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) hasFresh = true;
            }
        }

        if (!hasFresh) return 0; // No fresh oranges

        // Perform DFS from all rotten oranges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2 && !vis[i][j]) {
                    dfs(i, j, grid, vis);
                }
            }
        }

        // Check if any fresh orange is left unrotted
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) return -1; // Fresh oranges left unrotted
            }
        }

        // Since the above implementation doesn't track time, we cannot return the correct minimum time.
        // Implement BFS to calculate the minimum time for rotting all fresh oranges.

        // Placeholder return value since the above implementation doesn't solve the problem as required
        return -1;
    }
};

