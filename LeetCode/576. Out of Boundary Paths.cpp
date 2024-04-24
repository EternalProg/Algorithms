class Solution {
public:
    const int mod = 1000000007;

    int f(int x, int y, int maxMove, vector<vector<vector<int>>> &cacheMoves, int m, int n) {
        if (x < 0 || y < 0 || x == m || y == n) return 1;
        if (maxMove <= x && maxMove <= y && x + maxMove < m && y + maxMove < n) return 0;
        if(maxMove<=0) {
            return 0;
        }
        if (cacheMoves[x][y][maxMove] != -1) return cacheMoves[x][y][maxMove];
        long long result = 0;
        result += f(x - 1, y, maxMove - 1, cacheMoves, m, n) % mod;
        result += f(x, y - 1, maxMove - 1, cacheMoves, m, n) % mod;
        result += f(x + 1, y, maxMove - 1, cacheMoves, m, n) % mod;
        result += f(x, y + 1, maxMove - 1, cacheMoves, m, n) % mod;

        return cacheMoves[x][y][maxMove] = result % mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> cacheMoves(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));

        return f(startRow, startColumn, maxMove, cacheMoves, m, n);
    }
};

// https://youtu.be/TJuZXQltBqo
