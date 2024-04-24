class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);
        for (int i = 0; i < m; ++i) {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)
                    cur[j] = grid[i][j];
                else {
                    int up = grid[i][j];
                    int left = grid[i][j];
                    if (i > 0)
                        up += prev[j];
                    else
                        up += 1e9;

                    if (j > 0)
                        left += cur[j - 1];
                    else
                        left += 1e9;

                    cur[j] = min(up, left);
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};
