class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int white_cnt = 0;
        for(int i = s.size()-1; i >= 0; --i) {
            if(s[i] == '0') {
                ++white_cnt;                
            }
            else {
                ans += white_cnt;
            }
        }
        return ans;
    }
};
