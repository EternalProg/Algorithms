const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  int pivotInteger(int n) {
    if (n <= 1) return n;
    int sum = n * (n + 1) / 2;

    for (int i = 2; i < n; ++i) {
      int prefixSum = i * (i + 1) / 2;
      if (sum - prefixSum + i == prefixSum) return i;
    }
    return -1;
  }
};
