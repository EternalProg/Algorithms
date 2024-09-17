class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        istringstream iss1(s1);
        istringstream iss2(s2);

        string word;
        while(iss1 >> word) {
            ++freq[word];
        }
        while(iss2 >> word) {
            ++freq[word];
        }
        
        vector<string> ans;
        for(auto& [word, f]: freq) {
            if(f == 1) {
                ans.push_back(std::move(word));
            }
        }
        return ans;
    }
};
