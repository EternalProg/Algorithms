class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> a(n, 1);
    for (int i = n - 2; i >= 0; i--) {
      a[i] = nums[i + 1] * a[i + 1];
    }
    int b = 1;
    for (int j = 1; j < n; j++) {
      b *= nums[j - 1];
      a[j] *= b;
    }
    return a;
  }
};
