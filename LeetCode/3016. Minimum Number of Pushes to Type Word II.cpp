class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<char, int>> mp(26);
        for (char c : word) {
            mp[c - 'a'].first = c;
            ++mp[c - 'a'].second;
        }

        sort(mp.begin(), mp.end(),
             [](const pair<char, int>& lhs, const pair<char, int>& rhs) {
                 return lhs.second > rhs.second;
             });

        int ans = 0;
        int k = 1;
        for (int i = 0; i < mp.size(); ++i) {
            if (mp[i].second == 0)
                return ans;
            ans += mp[i].second * k;
            if ((i + 1) % 8 == 0)
                ++k;
        }
        return ans;
    }
};
