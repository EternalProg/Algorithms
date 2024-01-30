class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int fn = 0;
        int sn = 0;
        for(auto ch: tokens) {
            if(ch != "+" && ch != "-" && ch != "*" && ch != "/") {
                st.push(stoi(ch));
            }
            else if(ch == "+") {
                fn = st.top();
                st.pop();
                sn = st.top();
                st.pop();
                st.push(sn + fn);
            }
            else if(ch == "-") {
                fn = st.top();
                st.pop();
                sn = st.top();
                st.pop();
                st.push(sn - fn);
            }
            else if(ch == "*") {
                fn = st.top();
                st.pop();
                sn = st.top();
                st.pop();
                st.push(sn * fn);
            }
            else if(ch == "/") {
                fn = st.top();
                st.pop();
                sn = st.top();
                st.pop();
                st.push(sn / fn);
            }
        }
        return st.top();
    }
};
