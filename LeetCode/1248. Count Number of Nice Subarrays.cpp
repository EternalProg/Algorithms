class Solution {
public:
    int f(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int curr = 0;
        int res = 0;
        while(r < nums.size()) {
            if(nums[r] % 2 != 0) ++curr;

            while(curr > k) {
                if(nums[l] % 2 != 0) {
                    --curr;
                }
                ++l;
            }

            res += r - l + 1;
            ++r;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k - 1);
    }
};
