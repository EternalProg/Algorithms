class Solution {
 public:
  long long countSubarrays(vector<int>& nums, int k) {
    int mx = ranges::max(nums);
    int l = 0, r = 0;
    int cnt = 0;
    long long ans = 0;

    for (; l < nums.size(); ++l) {
      while (r < nums.size() && cnt < k) {
        cnt += nums[r] == mx;
        ++r;
      }

      if (cnt < k) break;

      ans += nums.size() - r + 1;

      cnt -= nums[l] == mx;
    }
    return ans;
  }
};
