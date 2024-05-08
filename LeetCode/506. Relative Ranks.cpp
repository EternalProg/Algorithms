const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();
    vector<string> ans(n, "");
    unordered_map<int, int> indices;
    for (int i = 0; i < n; ++i) {
      indices[score[i]] = i;
    }
    sort(score.begin(), score.end(), [](int a, int b) { return a > b; });
    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        ans[indices[score[i]]] = "Gold Medal";
      } else if (i == 1) {
        ans[indices[score[i]]] = "Silver Medal";
      } else if (i == 2) {
        ans[indices[score[i]]] = "Bronze Medal";
      } else {
        ans[indices[score[i]]] = to_string(i + 1);
      }
    }
    return ans;
  }
};
