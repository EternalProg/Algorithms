class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        
        vector<vector<int>> dp(m, vector<int>(n, 1e9));
        
        vector<int> pos[26];
        for(int i = 0; i < n; ++i) {
            pos[ring[i] - 'a'].push_back(i);
        }

        for(int index: pos[key[0] - 'a']) {
            dp[0][index] = min(index, n - index) + 1;
        }

         for (int i = 1; i < m; ++i) {
            for (int j : pos[key[i] - 'a']) {
                for (int k : pos[key[i - 1] - 'a']) {
                    int stepDiff = min(abs(j - k), n - abs(j - k)) + 1;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + stepDiff);
                }
            }
        }

        int res = 1e9;
        for(int index: pos[key[m - 1] - 'a']) {
            res = min(res, dp[m-1][index]);
        }
        return res;
    }
};
