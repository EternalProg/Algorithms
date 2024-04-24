class Solution {
public:
    int f(int start, int end, vector<int>& nums) {
        int evenSum = 0;
        int oddSum = 0;
        for(int i = start; i < end; ++i) {
            if(i % 2 == 0) evenSum = max(oddSum, evenSum + nums[i]);
            else oddSum = max(evenSum, oddSum + nums[i]);
        }
        return max(evenSum, oddSum);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max(f(0, n-1, nums), f(1, n, nums));
    }
};
