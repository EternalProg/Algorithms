class Solution {
 public:
  void backtrack(int i, vector<string>& cur, vector<string>& res,
                 const string& s, set<string>& wDict) {
    if (i == s.size()) {
      string cur_word = "";
      for (auto& word : cur) {
        cur_word += word + " ";
      }
      cur_word.pop_back();
      res.push_back(cur_word);
      return;
    }

    for (int j = i; j < s.size(); ++j) {
      string w(s.begin() + i, s.begin() + j + 1);
      if (wDict.count(w)) {
        cur.push_back(w);
        backtrack(j + 1, cur, res, s, wDict);
        cur.pop_back();
      }
    }
  }
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    set<string> wDict = set(wordDict.begin(), wordDict.end());
    vector<string> res;
    vector<string> cur;
    backtrack(0, cur, res, s, wDict);
    return res;
  }
};
