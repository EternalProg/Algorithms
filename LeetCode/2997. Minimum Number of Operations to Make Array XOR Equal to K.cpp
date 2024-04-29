class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorSum = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            xorSum ^= nums[i];
        }

        int result = 0;
        for (int i = 0; i < sizeof(int) * 8; ++i) {
            bool bit1 = (xorSum >> i) & 1;
            bool bit2 = (k >> i) & 1;

            if(bit1 != bit2) ++result;
        }
        return result;
    }
};
