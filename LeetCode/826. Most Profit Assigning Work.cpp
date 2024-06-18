const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> dif_prof;
        for (int i = 0; i < profit.size(); ++i) {
            dif_prof.emplace_back(difficulty[i], profit[i]);
        }

        sort(dif_prof.begin(), dif_prof.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0, res = 0, i = 0;
        for (auto& w : worker) {
            while (i < dif_prof.size() && dif_prof[i].first <= w) {
                maxProfit = max(maxProfit, dif_prof[i].second);
                ++i;
            }
            res += maxProfit;
        }
        return res;
    }
};
