const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> v_pair;
        for(int i = 0; i < nums.size(); ++i) {
            ++mp[nums[i]];
        }
        vector<int> ans;
        for(auto& [numb, freq]: mp) {
            v_pair.push_back({freq, numb});
        }
        sort(v_pair.begin(), v_pair.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            if(a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        for(auto& [freq, numb]: v_pair) {
            for(int i = 0; i < freq; ++i) {
                ans.push_back(numb);
            }
        }
        return ans;
    }
};
