class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int mf = 0;
        int X = 0;

        unordered_map<char, int> mp;
        for(auto ch: tasks) {
            ++mp[ch];
            if(mp[ch] > mf) {
                mf = mp[ch];
                X = 1;
            }
            else if(mp[ch] == mf) {
                ++X;
            }
        }
        return max((n+1)*(mf-1)+X, (int)tasks.size());
    }
};
