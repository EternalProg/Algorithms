class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0, zero = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                one++;
            else if (s[i] == '0')
                zero++;
        }
        string ans;
        if (one > 1) {
            for (int j = 0; j < one - 1; j++) {
                ans += '1';
            }
        }
        for (int k = 0; k < zero; k++) {
            ans += '0';
        }
        ans += '1';
        return ans;
    }
};
