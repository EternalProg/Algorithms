class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int currentSum = 0;
    int maxLength = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        ++currentSum;
      } else {
        --currentSum;
      }
      if (mp.count(currentSum)) {
        maxLength = max(maxLength, i - mp[currentSum]);
      } else {
        mp[currentSum] = i;
      }
    }
    return maxLength;
  }
};
