class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        for (int i = 0; i < land.size(); ++i) {
            for (int j = 0; j < land[0].size(); ++j) {
                if (land[i][j] == 1) {
                    int r1 = i, c1 = j, r2 = i, c2 = j;

                    while (r2 < land.size() && land[r2][c1] == 1) {
                        ++r2;
                    }

                    while (c2 < land[0].size() && land[r1][c2] == 1) {
                        ++c2;
                    }

                    ans.push_back({r1, c1, r2-1, c2-1});

                    for (int r = r1; r < r2; ++r) {
                        for (int c = c1; c < c2; ++c) {
                            land[r][c] = 0;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
