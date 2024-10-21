class Solution {
public:
  void dfs(int start, unordered_map<string, bool> &used, string &s,
           int &maxSplit, int currentSplit) {
    if (start == s.size()) {
      maxSplit = max(maxSplit, currentSplit);
      return;
    }

    string currString = "";
    for (int i = start; i < s.size(); ++i) {
      currString += s[i];

      if (!used[currString]) {
        used[currString] = true;
        dfs(i + 1, used, s, maxSplit, currentSplit + 1);
        used[currString] = false;
      }
    }
  }
  int maxUniqueSplit(string s) {
    unordered_map<string, bool> used;
    int maxSplit = 0;
    dfs(0, used, s, maxSplit, 0);
    return maxSplit;
  }
};
