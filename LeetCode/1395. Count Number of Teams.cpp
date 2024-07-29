const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
  void f(vector<int> &rating, int cur_indx, int &l_b, int &l_a, int &g_b,
         int &g_a) {
    for (int i = 0; i < cur_indx; ++i) {
      if (rating[i] > rating[cur_indx])
        ++g_b;
      else
        ++l_b;
    }
    for (int i = cur_indx + 1; i < rating.size(); ++i) {
      if (rating[i] > rating[cur_indx])
        ++g_a;
      else
        ++l_a;
    }
  }
  int numTeams(vector<int> &rating) {
    int n = rating.size();
    int count = 0;

    for (int j = 0; j < n; ++j) {
      int less_before = 0, less_after = 0;
      int greater_before = 0, greater_after = 0;

      f(rating, j, less_before, less_after, greater_before, greater_after);

      count += less_before * greater_after + greater_before * less_after;
    }

    return count;
  }
};
