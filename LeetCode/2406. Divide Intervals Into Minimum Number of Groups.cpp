class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> starts(n, 0);
        vector<int> ends(n, 0);

        for(int i = 0; i < n; ++i) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int sp = 0;
        int ep = 0;

        int ans = 0;
        while(sp < n) {
            if(starts[sp] <= ends[ep]) {
                ++sp;
            }
            else {
                ++ep;
            }

            ans = max(ans, sp - ep);
        }
        return ans;
    }
};
