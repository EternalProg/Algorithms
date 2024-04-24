class Solution {
public:
    int rob(vector<int>& nums) {
        int evenSum = 0;
        int oddSum = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(i % 2 == 0) {
                evenSum = max(oddSum, evenSum + nums[i]);
            }
            else {
                oddSum = max(evenSum, oddSum + nums[i]);
            }
        }
        return max(evenSum, oddSum);
    }
};
