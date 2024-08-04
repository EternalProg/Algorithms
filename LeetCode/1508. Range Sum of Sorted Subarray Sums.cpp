class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod = 1e9 + 7;
        int all_sum = n * (n + 1) / 2;
        vector<int> v;
        v.reserve(all_sum);
        for (int i = 0; i < nums.size(); ++i) {
            int sum = nums[i];
            v.push_back(sum);
            for (int j = i + 1; j < nums.size(); ++j) {
                sum += nums[j];
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + v[i]) % mod;
        }
        return ans;
    }
};
