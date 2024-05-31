class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto& numb: nums) {
            ++mp[numb];
        }

        for(auto& [numb, freq]: mp) {
            if(freq == 1) ans.push_back(numb);
        }
        return ans;
    }
};
