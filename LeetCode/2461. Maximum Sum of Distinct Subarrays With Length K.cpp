class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        unordered_map<int, bool> mp;

        int l = 0;
        int r = 0;
        long long curr_sum = 0;

        while (r < nums.size()) {
            curr_sum += nums[r];

            while (mp[nums[r]] || r - l + 1 > k) {
                mp[nums[l]] = false;
                curr_sum -= nums[l];
                ++l;
            }

            if (r - l + 1 == k) {
                maxSum = max(maxSum, curr_sum);
            }

            mp[nums[r]] = true;
            ++r;
        }
        return maxSum;
    }
};
