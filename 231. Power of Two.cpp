class Solution {
public:
    bool isPowerOfTwo(long n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};
