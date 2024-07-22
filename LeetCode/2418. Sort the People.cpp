class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> v_pair(names.size());
        for(int i = 0; i < names.size(); ++i) {
            v_pair[i] = {heights[i], names[i]};
        }

        sort(v_pair.begin(), v_pair.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });
        
        vector<string> result;
        for(const auto& [h, n]: v_pair) {
            result.push_back(n);
        }
        return result;
    }
};
