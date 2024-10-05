class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char ch: s1) {
            ++freq1[ch-'a'];
        }

        int l = 0;
        for(int r = 0; r < m; ++r) {
            ++freq2[s2[r] - 'a'];

            if(r - l + 1 == n) {
                if(freq1 == freq2) return true;

                --freq2[s2[l] - 'a'];
                ++l;
            }
        }
        return false;

    }
};
