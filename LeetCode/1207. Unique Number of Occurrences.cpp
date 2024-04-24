class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0; i < arr.size(); ++i) {
            ++mp[arr[i]];
        }

        unordered_set<int> uniqueOccurrences;
        for (const auto& entry : mp) {
            if (!uniqueOccurrences.insert(entry.second).second) {
                return false;
            }
        }
        return true;
    }
};
