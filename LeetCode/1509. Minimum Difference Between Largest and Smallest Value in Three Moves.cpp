class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for(int l = 0; l < 4; ++l) {
            int r = nums.size() - 4 + l;
            res = min(res, nums[r]-nums[l]); 
        }
        return res;
    }
};
