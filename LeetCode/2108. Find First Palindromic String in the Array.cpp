const int ZERO = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();

class Solution {
 public:
  bool isPalindrome(string& str) {
    int left = 0, right = str.size() - 1;
    while (left <= right) {
      if (str[left] != str[right]) return false;
      ++left, --right;
    }
    return true;
  }
  string firstPalindrome(vector<string>& words) {
    for (auto str : words) {
      if (isPalindrome(str)) return str;
    }
    return "";
  }
};
