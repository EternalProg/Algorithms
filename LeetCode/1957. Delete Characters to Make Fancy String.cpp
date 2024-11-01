class Solution {
public:
    string makeFancyString(string s) {
        int count_prev = 0;
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                if (count_prev < 2) {
                    res.push_back(s[i]);
                    ++count_prev;
                }
            } else {
                res.push_back(s[i]);
                count_prev = 1;
            }
        }
        return res;
    }
};
