class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; --i) {
            int cur_width = shelfWidth;
            int max_height = 0;

            dp[i] = 1e9;

            for(int j = i; j < n; ++j) {
                int width = books[j][0];
                int height = books[j][1];

                if(cur_width < width) {
                    break;
                }

                cur_width -= width;
                max_height = max(max_height, height);

                dp[i] = min(dp[i], dp[j+1] + max_height);
            }
        }
        return dp[0];
    }
};
