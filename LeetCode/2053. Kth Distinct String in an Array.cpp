class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(string& str: arr) {
            ++mp[str];
        }
        if(mp.size() < k) return "";
        int distinct_indx = 1;
        for(int i = 0; i < arr.size(); ++i) {
            if(mp[arr[i]] == 1) {
                if(distinct_indx == k) return arr[i];
                ++distinct_indx;
            }
        }
        return "";
    }
};
