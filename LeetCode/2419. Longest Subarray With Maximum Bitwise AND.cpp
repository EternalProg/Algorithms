class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int max_value = 0;
        int current_length = 0;

        for(int i = 0; i < n; ++i) {
            if(nums[i] > max_value) {
                max_value = nums[i];
                current_length = 0;
                ans = 0;
            }

            if(nums[i] == max_value) {
                ++current_length;
            }
            else {
                current_length = 0;
            }
            ans = max(current_length, ans);
        }
        return ans;
    }
};
