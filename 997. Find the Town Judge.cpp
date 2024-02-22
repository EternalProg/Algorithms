const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count(n + 1, 0);
        for (int i = 0; i < trust.size(); i++) {
            count[trust[i][1]]++;
            count[trust[i][0]]--;
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (count[i] == n - 1) {
                return i;
            }
        }
        return ans;
    }
};
