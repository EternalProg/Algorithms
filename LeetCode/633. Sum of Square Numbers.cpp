class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0 || c == 1) return true;
        long start = 0, end = sqrt(c);
        while(start <= end) {
            long sum = pow(start,2) + pow(end,2);
            if(sum == c) return true;
            else if(sum > c) --end;
            else ++start;
        }
        return false;
    }
};
