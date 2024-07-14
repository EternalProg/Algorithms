class Solution {
public:
    string countOfAtoms(string exp) {
        map<string, int> atoms;
        string ans;
        int cnt = 0, mult = 1;
        stack<int> st;
        
        for (int i = size(exp) - 1; i >= 0; i--) {
            if (isalpha(exp[i]) and islower(exp[i])) {
                int len = 2;
                i--;
                
                while (i >= 0 and islower(exp[i])) {
                    i--;
                    len++;
                }
                
                string atom = exp.substr(i, len);
                atoms[atom] += max(cnt, 1) * mult;
                cnt = 0;
            } else if (isalpha(exp[i]) and isupper(exp[i])) {
                string atom(1, exp[i]);
                atoms[atom] += max(cnt, 1) * mult;
                cnt = 0;
            } else if (isdigit(exp[i])) {
                cnt = exp[i] - '0';
                int p = 10;
                
                while (i - 1 >= 0 and isdigit(exp[i - 1])) {
                    cnt += p * (exp[--i] - '0');
                    p *= 10;
                }
            } else if (exp[i] == ')') {
                st.push(mult);
                mult *= max(cnt, 1);
                cnt = 0;
            } else {
                mult = st.top();
                st.pop();
            }
        }
        
        for (auto [atom, count]: atoms) {
            ans += atom;
            
            if (count > 1) {
                ans += to_string(count);
            }
        }
        
        return ans;
    }
};
