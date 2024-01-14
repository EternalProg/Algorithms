class Solution {
public:
    bool closeStrings(string word1, string word2)
    {
        if(word1.size() != word2.size())
            return false;

        vector<int> v1(26,0),v2(26,0),v11(26,0),v22(26,0);

        for (auto c: word1)
        {
            v1[c - 'a']++;
            v11[c - 'a'] = 1;
        }

        for (auto c: word2)
        {
            v2[c - 'a']++;
            v22[c - 'a'] = 1;
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        return (v1 == v2 && v11 == v22);
    }
};
