class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> v(128);
        for(const auto &ch: s) {
            v[ch].second = ch;
            ++v[ch].first;
        }

        sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
            return (a.first > b.first);
        });

        string ans = "";
        for(const auto &pair : v) {
            ans += string(pair.first, pair.second);
        }
        return ans;
    }
};
