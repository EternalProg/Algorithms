class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        for(int len = 2; len <= s.size(); ++len) {
            for(int startIndx = 0; startIndx <= s.size()-len; ++startIndx) {
                string temp = s.substr(startIndx, len);
                int numb = stoi(temp);

                if(numb >= low && numb <= high)
                    ans.push_back(numb);
            }
        }
        return ans;
    }
};
