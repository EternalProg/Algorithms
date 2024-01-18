class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) {
            return n;
        }

        int temp1 = 1;
        int temp2 = 2;

        for(int i = 2; i < n; ++i) {
            int temp3 = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp3;
        }

        return temp2;
    }
};
