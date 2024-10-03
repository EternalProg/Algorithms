class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }

        if (totalSum == 0) return 0;

        unordered_map<int, int> prefixRemainder;
        prefixRemainder[0] = -1;
        int currentSum = 0;
        int minLength = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            currentSum = (currentSum + nums[i]) % p;
            int target = (currentSum - totalSum + p) % p;

            if (prefixRemainder.find(target) != prefixRemainder.end()) {
                minLength = min(minLength, i - prefixRemainder[target]);
            }

            prefixRemainder[currentSum] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};
