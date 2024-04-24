class Solution {
public:
    int minOperations(vector<int>& nums) {
        int result = 0;
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); ++i) {
            ++mp[nums[i]];
        }

        for(auto& pair : mp) {
            int count = pair.second;
            if(count == 1) return -1;

            result += (count + 2)/3;
        }
        return result;
    }
};
