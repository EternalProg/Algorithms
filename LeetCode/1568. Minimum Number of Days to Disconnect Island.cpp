class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j])
            return;
        visited[i][j] = true;

        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j+1);
        dfs(grid, visited, i, j-1);
    }

    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;


        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find a land cell that is not visited, start a new DFS
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(grid, visited, i, j); // Explore the island
                }
            }
        }
        return count;
    }
    
    int minDays(vector<vector<int>>& grid) {
        if (countIslands(grid) != 1) return 0;
        
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; // Remove the land cell
                    // Check if removing this cell disconnects the grid
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1; // Restore the land cell
                }
            }
        }

        return 2;
    }
};
