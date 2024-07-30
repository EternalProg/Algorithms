class Solution {
public:
    int minimumDeletions(string s) {
        int a_after = 0;
        for (int i = 0; i < s.size(); ++i) {
            a_after += s[i] == 'a';
        }

        int b_before = 0;
        int ans = a_after;

        for (int i = 0; i < s.size(); ++i) {
            a_after -= s[i] == 'a';
            b_before += s[i] == 'b';
            ans = min(ans, a_after + b_before);
        }
        return ans;
    }
};
