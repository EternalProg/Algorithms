class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);

        map<int,int> loses;

        for(int i = 0; i < matches.size(); ++i) {
            ++loses[matches[i][1]];
        }
        for(int i = 0; i < matches.size(); ++i) {
            if (!loses.count(matches[i][0])) {
                loses[matches[i][0]] = -1;
            }
        }
        for(auto it: loses) {
            if(it.second == 1) {
                ans[1].push_back(it.first);
            }
            if(it.second == -1)
                ans[0].push_back(it.first);
        }
        return ans;
    }
};
