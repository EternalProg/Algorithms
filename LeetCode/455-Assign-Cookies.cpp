class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  
        sort(s.begin(), s.end());

        int gIndex = 0;
        int sIndex = 0;

        while (gIndex < g.size() && sIndex < s.size()) {
            if (s[sIndex] >= g[gIndex]) {
                ++gIndex;
            }
            ++sIndex;
        }

        return gIndex;
    }
};
