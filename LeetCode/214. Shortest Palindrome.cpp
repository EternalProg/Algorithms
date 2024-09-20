class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        string combined = s + "#" + rev_s;
        
        vector<int> kmp(combined.size(), 0);
        
        for (int i = 1; i < combined.size(); ++i) {
            int j = kmp[i - 1];
            
            while (j > 0 && combined[i] != combined[j]) {
                j = kmp[j - 1];
            }
            
            if (combined[i] == combined[j]) {
                ++j;
            }
            
            kmp[i] = j;
        }
        
        int palindrome_length = kmp.back();
        
        return rev_s.substr(0, s.size() - palindrome_length) + s;
    }
};
