const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
 public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());
    int amount_of_boats = 0;
    int i = 0, j = people.size() - 1;

    while (i <= j) {
      if (people[i] + people[j] <= limit) {
        ++amount_of_boats, ++i, --j;
      } else {
        ++amount_of_boats, --j;
      }
    }
    return amount_of_boats;
  }
};
