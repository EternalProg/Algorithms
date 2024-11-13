class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;

        for (int i = 0; i < n; ++i) {
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto up = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);

            res += up - low;
        }

        return res;
    }
};
