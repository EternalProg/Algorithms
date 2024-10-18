class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxBitwise = 0;
        int totalSubsets = 1 << n;
        for (int num : nums) {
            maxBitwise |= num;
        }

        for (int mask = 0; mask < totalSubsets; ++mask) {
            int currBitwise = 0;

            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    currBitwise |= nums[i];
                }
            }
            if (currBitwise == maxBitwise) {
                ++ans;
            }
        }

        return ans;
    }
};
