class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> edge_cnt(n, 0);

        for(int i = 0; i < roads.size(); ++i) {
            ++edge_cnt[roads[i][0]]; 
            ++edge_cnt[roads[i][1]];
        }

        long long label = 1;
        long long res = 0;
        sort(edge_cnt.begin(), edge_cnt.end());
        for(int count: edge_cnt) {
            res += label * count;
            ++label;
        }
        return res;
    }
};
