const int speed = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string tempStack;
        int count = 0;

        for(auto ch: s) {
            if(ch == ')' && count == 0) continue;
            else if(ch == '(') ++count;
            else if(ch == ')') --count;
            tempStack.push_back(ch);
        }

        string result;
        count = 0;

        while(!tempStack.empty()) {
            char c = tempStack.back();
            tempStack.pop_back();
            if(c == '(' && count == 0) continue;
            else if(c == ')') ++count;
            else if(c == '(') --count;
            result.push_back(c);
        }

        reverse(result.begin(), result.end());
        return result;

    }
};
