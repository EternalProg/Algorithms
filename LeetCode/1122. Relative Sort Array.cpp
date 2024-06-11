class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto numb: arr1) ++mp[numb];
        vector<int> ans;
        for(auto& numb: arr2) {
            for(int i = 0; i < mp[numb]; ++i) {
                ans.push_back(numb);
            }
            mp[numb] = 0;
        }
        for(auto& [numb, freq]: mp) {
            if(freq > 0) {
                for(int i = 0; i < freq; ++i) {
                    ans.push_back(numb);
                }
            }
        }
        return ans;
    }
};
