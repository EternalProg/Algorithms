class Solution {
public:
    int tribonacci(int n) {
        int T0 = 0, T1 = 1, T2 = 1;
        if(n < 2) return n;

        for(int i = 3; i <= n; ++i){
            int tmp = T0 + T1 + T2;
            T0 = T1, T1 = T2, T2 = tmp;
        }
        return T2;
    }
};
