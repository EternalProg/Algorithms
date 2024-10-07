class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char ch : s) {
            if (st.empty()) {
                st.push(ch);
            }
            else if (ch == 'B' && st.top() == 'A') {
                st.pop();
            } else if (ch == 'D' && st.top() == 'C') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.size();
    }
};
