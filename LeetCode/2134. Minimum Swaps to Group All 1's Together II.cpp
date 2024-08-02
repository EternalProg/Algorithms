
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count_ones = 0;
        for (int num : nums) {
            if (num == 1) {
                ++count_ones;
            }
        }

        if (count_ones == 0 || count_ones == nums.size()) {
            return 0;
        }

        vector<int> double_nums(nums.begin(), nums.end());
        double_nums.insert(double_nums.end(), nums.begin(), nums.end());

        int max_ones_in_window = 0, current_ones_in_window = 0;

        for (int i = 0; i < count_ones; ++i) {
            if (double_nums[i] == 1) {
                ++current_ones_in_window;
            }
        }

        max_ones_in_window = current_ones_in_window;

        for (int i = count_ones; i < double_nums.size(); ++i) {
            if (double_nums[i] == 1) {
                ++current_ones_in_window;
            }
            if (double_nums[i - count_ones] == 1) {
                --current_ones_in_window;
            }
            max_ones_in_window =
                max(max_ones_in_window, current_ones_in_window);
        }

        return count_ones - max_ones_in_window;
    }
};
