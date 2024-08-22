class Solution {
public:
    int findComplement(int num) {
        int i = 0;
        int numb = num;
        for (; num != 0; ++i) {
            num >>= 1;
        }
        return (long)(1 << i) - 1 ^ numb; // (2^i - 1) ^ numb
    }
};
