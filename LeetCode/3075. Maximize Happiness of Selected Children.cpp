const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    long long result = 0;
    sort(happiness.begin(), happiness.end(),
         [](int a, int b) { return a > b; });
    for (int i = 0; i < k; ++i) {
      if (happiness[i] - i <= 0)
        return result;
      else
        result += happiness[i] - i;
    }
    return result;
  }
};
