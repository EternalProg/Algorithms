class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        vector<int> freq(3, 0);

        for(char ch: s) {
            ++freq[ch - 'a'];
        }

        for(int i = 0; i < 3; ++i) {
            if(freq[i] < k) return -1;
        }

        int l = 0;
        
        int dist = 0;
        for(int r = 0; r < s.size(); ++r) {
            --freq[s[r] - 'a'];

            while(freq[0] < k || freq[1] < k || freq[2] < k) {
                ++freq[s[l] - 'a'];
                ++l;
            }
            dist = max(dist, r - l + 1);
        }

        return s.size() - dist;
    }
};
