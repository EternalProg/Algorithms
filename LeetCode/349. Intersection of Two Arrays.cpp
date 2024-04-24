const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    unordered_map<int, bool> visited;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j] && !visited[nums1[i]]) {
        result.push_back(nums1[i]);
        visited[nums1[i]] = true;
        ++i, ++j;
      }

      else if (nums1[i] > nums2[j])
        ++j;
      else
        ++i;
    }

    return result;
  }
};
