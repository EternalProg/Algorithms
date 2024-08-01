class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i = 0; i < details.size(); ++i) {
            ans += stoi(details[i].substr(11,2)) > 60;
        }
        return ans;
    }
};
