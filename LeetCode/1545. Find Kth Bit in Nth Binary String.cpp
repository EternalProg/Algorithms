class Solution {
public:
    char findKthBit(int n, int k) {
        return findKthBitHelper(n, k);
    }

private:
    char findKthBitHelper(int n, int k) {
        if (n == 1) {
            return '0';
        }

        int len = (1 << n) - 1;
        int mid = len / 2 + 1;

        if (k == mid) {
            return '1'; 
        } else if (k < mid) {
            return findKthBitHelper(n - 1, k);
        } else {
            return invert(findKthBitHelper(n - 1, len - k + 1));
        }
    }

    char invert(char c) {
        return c == '0' ? '1' : '0';
    }
};
    
