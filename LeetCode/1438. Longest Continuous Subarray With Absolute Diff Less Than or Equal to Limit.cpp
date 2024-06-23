class Solution {
public:
        int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int i = 0, j;
        for (j = 0; j < nums.size(); ++j) {
            while (!maxd.empty() && nums[j] > maxd.back()) maxd.pop_back();
            while (!mind.empty() && nums[j] < mind.back()) mind.pop_back();
            maxd.push_back(nums[j]);
            mind.push_back(nums[j]);
            if (maxd.front() - mind.front() > limit) {
                if (maxd.front() == nums[i]) maxd.pop_front();
                if (mind.front() == nums[i]) mind.pop_front();
                ++i;
            }
        }
        return j - i;
    }
};
