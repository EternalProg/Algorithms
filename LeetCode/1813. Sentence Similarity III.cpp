class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1;
        vector<string> words2;

        istringstream iss(sentence1);
        string word;

        while(iss >> word) {
            words1.push_back(word);
        }

        istringstream iss2(sentence2);
        while(iss2 >> word) {
            words2.push_back(word);
        }

        int l = 0;
        int r = 0;

        // Порівняння з початку
        while (l < words1.size() && l < words2.size() && words1[l] == words2[l]) {
            ++l;
        }

        // Порівняння з кінця
        while (r < words1.size() - l && r < words2.size() - l &&
               words1[words1.size() - 1 - r] == words2[words2.size() - 1 - r]) {
            ++r;
        }

        // Перевірка чи l + r охоплює найкоротше речення
        return l + r >= min(words1.size(), words2.size());
    }
};
