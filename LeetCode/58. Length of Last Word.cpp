class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                int j = i + 1;
                while (s[j] != ' ' && j < s.size()) {
                    ++j;
                }
                ans = j - i;
                i = j;
            }
        }
        return ans;
    }
};
