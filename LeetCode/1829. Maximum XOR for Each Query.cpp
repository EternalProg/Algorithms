class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n);

        int maxK = (1 << maximumBit) - 1;
        int allXor = 0;
        for(int numb: nums) {
            allXor ^= numb;
        }

        for(int i = n-1; i >= 0; --i) {
            ans.push_back(allXor ^ maxK);
            allXor ^= nums[i];
        }
        return ans;
    }
}; 
