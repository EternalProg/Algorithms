class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end());
        ans.push_back(folder[0]);

       std::function<bool(int)> isSubFolder = [&](int i) {
            if (folder[i].size() < ans.back().size()) {
                return false;
            }
            if (folder[i].substr(0, ans.back().size()) == ans.back() && 
                folder[i][ans.back().size()] == '/') {
                return true;
            }
            return false;
        };

        for(int i = 1; i < folder.size(); ++i) {
            if(!isSubFolder(i)) {
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};
