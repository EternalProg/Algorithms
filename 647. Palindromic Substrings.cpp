class Solution {
public:
    int isPalindrome(int i, int j, vector<vector<int>> &dp, string &s) {
        if(i >= j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = s[i] == s[j] ? isPalindrome(i+1, j-1, dp, s) : 0;
    }
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int count = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                count += isPalindrome(i, j, dp, s);
            }
        }
        return count;
    }
};
