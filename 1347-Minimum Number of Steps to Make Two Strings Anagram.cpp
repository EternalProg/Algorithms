class Solution {
 public:
  int minSteps(string s, string t) {
    /*
            int result = 0;
            unordered_map<char,int> mp;

            for(auto it: s) {
                ++mp[it];
            }
            for(auto it: t) {
                --mp[it];
            }
            for (auto& entry : mp) {
                result += abs(entry.second);
            }

            return result/2;
    */
    int s1[26] = {0}, t1[26] = {0};
    int ans = 0;
    for (auto x : s) s1[x - 'a']++;
    for (auto x : t) t1[x - 'a']++;
    for (int i = 0; i < 26; i++) {
      if (t1[i] - s1[i] > 0) ans += t1[i] - s1[i];
    }
    return ans;
  }
};
