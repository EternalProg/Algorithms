class Solution {
public:
    bool is_magic_square(const vector<vector<int>>& grid, int start_row, int start_col) {
        vector<int> count(10, 0);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = grid[start_row + i][start_col + j];
                if (num < 1 || num > 9 || ++count[num] > 1)
                    return false;
            }
        }

        int sum = grid[start_row][start_col] + grid[start_row][start_col + 1] + grid[start_row][start_col + 2];

        return (grid[start_row][start_col] + grid[start_row + 1][start_col] + grid[start_row + 2][start_col] == sum) &&
               (grid[start_row][start_col + 2] + grid[start_row + 1][start_col + 2] + grid[start_row + 2][start_col + 2] == sum) &&
               (grid[start_row][start_col] + grid[start_row + 1][start_col + 1] + grid[start_row + 2][start_col + 2] == sum) &&
               (grid[start_row + 2][start_col] + grid[start_row + 1][start_col + 1] + grid[start_row][start_col + 2] == sum) &&
               (grid[start_row + 1][start_col] + grid[start_row + 1][start_col + 1] + grid[start_row + 1][start_col + 2] == sum) &&
               (grid[start_row][start_col + 1] + grid[start_row + 1][start_col + 1] + grid[start_row + 2][start_col + 1] == sum);
    }
     
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n < 3 || m < 3) return 0;

        int ans = 0;

        for(int row = 0; row < n-2; ++row) {
            for(int col = 0; col < m-2; ++col) {
                if(is_magic_square(grid, row, col)) ++ans;
            }
        }
        return ans;
    }
};
