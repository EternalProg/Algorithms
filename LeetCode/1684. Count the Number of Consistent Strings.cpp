class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans = 0;
        vector<char> all(26, 0);
        for(char ch: allowed) {
            ++all[ch - 'a'];
        }

        for(const string& word: words) {
            bool consistent = true;
            for(char ch: word) {
                if(!all[ch - 'a']) {
                    consistent = false;
                    break;
                }
            }
            ans += consistent == true;
        }
        return ans;
    }
};
