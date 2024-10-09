class Solution {
public:
    int minAddToMakeValid(string s) {
        int opened = 0;
        int closed = 0;
        for(char ch: s) {
            if(ch == ')') {
                if(opened > 0) {
                    --opened;
                }
                else {
                    ++closed;
                }
            }
            else {
                ++opened;
            }
        }
        return opened + closed;;
    }
};
