class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int> dp;
        int res = 0;
        sort(nums.begin(), nums.end());

        for(int numb: nums) {
            int root = sqrt(numb);
            if(root * root == numb) {
                dp[numb] = 1 + dp[root];
            }
            else {
                dp[numb] = 1;
            }
            res = max(res, dp[numb]);
        }
        return res < 2 ? -1 : res;
    }
};
