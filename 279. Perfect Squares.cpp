class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(1+n, 5);
        dp[0] = 0;
        for(int sum = 1; sum <= n; ++sum) {
            for(int first = 1; first*first <= sum; ++first) {
                dp[sum] = min(dp[sum], 1 + dp[sum - first*first]);
            }
        }
        return dp[n];
    }
};
