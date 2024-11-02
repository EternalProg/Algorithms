class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        string word;
        istringstream is(sentence);

        while (is >> word) {
            words.push_back(word);
        }

        if (words.front()[0] != words.back().back()) {
            return false;
        }

        for (int i = 1; i < words.size(); ++i) {
            if (words[i - 1].back() != words[i].front()) {
                return false;
            }
        }

        return true;
    }
};
