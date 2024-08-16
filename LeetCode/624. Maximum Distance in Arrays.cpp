class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int min_val = arrays[0][0];
        int max_val = arrays[0].back();
        int ans = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            ans = max(ans, max(abs(arrays[i].back() - min_val), abs(max_val - arrays[i][0])));
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i].back());
        }

        return ans;
    }
};
