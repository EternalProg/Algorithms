class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        int same_char = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                ++same_char, ++i, ++j;
            }

            else ++i;
        }
        return t.size() - same_char;
    }
};
