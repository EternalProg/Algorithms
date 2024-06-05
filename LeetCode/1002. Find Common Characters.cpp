class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> chars(26,100);
        for (auto s : words) {
            vector<int> chars2(26,0);
            for (auto ch : s) chars2[ch - 'a']++;
            for (int i = 0; i < 26; i++) chars[i] = min(chars[i], chars2[i]);
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < chars[i]; j++)
                ans.push_back({static_cast<char>('a' + i)});

        return ans;
    }
};
