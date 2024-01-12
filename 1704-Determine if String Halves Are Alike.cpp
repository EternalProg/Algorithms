class Solution {
public:

    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int count = 0;
        int size = s.size();
        int mid = size/2;

        for(int i = 0; i < size; ++i) {
            if(vowels.count(s[i]))
                i < mid ? ++count : --count;
        }

        return count == 0;
    }
};
