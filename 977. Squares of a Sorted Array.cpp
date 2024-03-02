const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int s = 0, e = nums.size() - 1;
    vector<int> ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
      if (abs(nums[s]) >= abs(nums[e])) {
        ans[i] = nums[s] * nums[s];
        ++s;
      } else {
        ans[i] = nums[e] * nums[e];
        --e;
      }
    }
    return ans;
  }
};
