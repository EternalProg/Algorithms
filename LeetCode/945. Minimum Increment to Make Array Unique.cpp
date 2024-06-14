
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, need = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < need) {
                ans += need - nums[i];
            }

            need = max(nums[i], need) + 1;
        }

        return ans;
    }
};
