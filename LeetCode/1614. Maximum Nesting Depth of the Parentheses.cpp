class Solution {
public:
    int maxDepth(string s) {
        int maxCounter = 0;
        int counter = 0;
        for(char ch: s) {
            if(ch == '(') ++counter;
            else if(ch == ')') --counter;
            maxCounter = max(maxCounter, counter);
        }
        return maxCounter;
    }
};
