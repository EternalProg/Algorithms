const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    for (auto numb : arr) {
      ++mp[numb];
    }

    vector<pair<int, int>> sortedPairs(mp.begin(), mp.end());
    sort(sortedPairs.begin(), sortedPairs.end(),
         [](const auto& a, const auto& b) { return a.second < b.second; });

    int ans = mp.size();
    for (const auto& pair : sortedPairs) {
      k -= pair.second;
      if (k >= 0) {
        --ans;
      } else
        break;
    }

    return ans;
  }
};
