class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& g1, vector<vector<int>>& g2, int& ans, bool& b) {
        if(r < 0 || c < 0 || r >= g1.size() || c >= g1[0].size() || g2[r][c] == 0) return;

        if (g1[r][c] == 0) {
            b = false;
            return;
        }

        g2[r][c] = 0;
        dfs(r-1, c, g1, g2, ans, b);
        dfs(r+1, c, g1, g2, ans, b);
        dfs(r, c-1, g1, g2, ans, b);
        dfs(r, c+1, g1, g2, ans, b);

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int ans = 0;
        bool b = true;

        for(int row = 0; row < m; ++row) {
            for(int col = 0; col < n; ++col) {
                if(grid2[row][col]) {
                    dfs(row, col, grid1, grid2, ans, b);
                    if(b) ++ans;
                    b = true;
                }
            }
        }
        return ans;
    }
};
