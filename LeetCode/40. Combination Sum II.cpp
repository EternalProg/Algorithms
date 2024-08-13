class Solution {
public:
    void f(vector<int>& candidates, int target, vector<vector<int>>& ans,
           vector<int>& cur_candidate, int i) {
        if (target == 0) {
            ans.push_back(cur_candidate);
            return;
        }

        for (int j = i; j < candidates.size(); ++j) {
            if (j > i && candidates[j] == candidates[j - 1])
                continue;

            if (candidates[j] > target)
                break;

            cur_candidate.push_back(candidates[j]);
            f(candidates, target - candidates[j], ans, cur_candidate, j + 1);
            cur_candidate.pop_back();
        }
    }
    auto combinationSum2(vector<int>& candidates, int target)
        -> vector<vector<int>> 
    {
        vector<vector<int>> ans;
        vector<int> cur_candidate;

        sort(candidates.begin(), candidates.end());

        f(candidates, target, ans, cur_candidate, 0);

        return ans;
    }
};
