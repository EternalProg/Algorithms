class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int maxK = -1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == 0) {
                maxK = max(maxK, nums[right]);
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
        return maxK;
    }
};
