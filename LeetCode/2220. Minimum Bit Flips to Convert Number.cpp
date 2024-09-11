class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_res = start ^ goal;
        int ans = 0;
        while(xor_res > 0) {
            ans += xor_res & 1;
            xor_res >>= 1;
        }
        return ans;
    }
};
