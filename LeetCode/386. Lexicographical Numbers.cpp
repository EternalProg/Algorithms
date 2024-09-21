class Solution {
public:
    void dfs(int curr_number, vector<int>& ans, int n) {
        if(curr_number > n) return;

        ans.push_back(curr_number);
        for(int i = 0; i < 10; ++i) {
            dfs(curr_number * 10 + i, ans, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        ans.reserve(n);
        for(int i = 1; i < 10; ++i) {
            dfs(i, ans, n);
        }
        return ans;
    }
};
