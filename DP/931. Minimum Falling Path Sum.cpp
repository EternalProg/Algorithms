
class Solution {
public:/*
    int f(int row, int col, vector<vector<int>>& matrix,
          vector<vector<int>>& dp, int n) {
        if (row == n - 1)
            return matrix[row][col];

        if (dp[row][col] != -101)
            return dp[row][col];

        int diagR = INT_MAX;
        if (col > 0)
            diagR = f(row + 1, col - 1, matrix, dp, n);

        int diagL = INT_MAX;
        if (col + 1 < n)
            diagL = f(row + 1, col + 1, matrix, dp, n);

        int directly = f(row + 1, col, matrix, dp, n);

        return dp[row][col] = matrix[row][col] + min({diagR, diagL, directly});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -101));

        int mini = INT_MAX;
        for (int col = 0; col < n; ++col) {
            mini = min(mini, f(0, col, matrix, dp, n));
        }

        return mini;
    }
*/
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }

        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int up = matrix[i][j] + dp[i-1][j];

                int leftD = matrix[i][j];
                if(j-1 >= 0) {
                    leftD += dp[i-1][j-1];
                }
                else {
                    leftD = 1e9;
                }

                int rightD = matrix[i][j];
                if(j + 1 < n) {
                    rightD += dp[i-1][j+1];
                }
                else {
                    rightD = 1e9;
                }

                dp[i][j] = min({up, leftD, rightD});
            }
        }

        int mini = INT_MAX;
        for(int i = 0; i < n; ++i) {
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
    }
};
