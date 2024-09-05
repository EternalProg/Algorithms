class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(int numb: rolls) {
            sum += numb;
        }

        int need_sum = mean * (n + m) - sum;
        if(need_sum < n || need_sum > 6 * n) return {};

        vector<int> ans(n, need_sum / n);
        int remainder = need_sum % n;

        for(int i = 0; i < remainder; ++i) {
            ++ans[i];
        }

        return ans;
    }
};
