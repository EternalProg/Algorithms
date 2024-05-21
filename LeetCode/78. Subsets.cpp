class Solution {
public:
    void dfs(int i, const vector<int>& nums, vector<int>& curr_subset, vector<vector<int>>& res) {
        if(i >= nums.size()) {
            res.push_back(curr_subset);
            return;
        }

        // include nums[i]
        curr_subset.push_back(nums[i]);
        dfs(i+1, nums, curr_subset, res);

        // NOT include nums[i]
        curr_subset.pop_back();
        dfs(i+1, nums, curr_subset, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr_subset;
        vector<vector<int>> res;
        dfs(0, nums, curr_subset, res);
        return res;
    }
};
