class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end])
                return false;
            ++start, --end;
        }
        return true;
    }
    void dfs(int i, const string& s, vector<string>& curr_str, vector<vector<string>>& res) {
        if(i >= s.size()) {
            res.push_back(curr_str);
            return;
        }

        for(int j = i; j < s.size(); ++j) {
            if(isPalindrome(s, i, j)) {
                curr_str.push_back(s.substr(i, j - i + 1));
                dfs(j+1, s, curr_str, res);
                curr_str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr_str;
        dfs(0, s, curr_str, res);
        return res;
    }
};
