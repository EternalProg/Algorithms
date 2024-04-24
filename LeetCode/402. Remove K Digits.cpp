
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";

        for(size_t i = 0; i < num.size()-1 && k > 0; ++i) {
            if(num[i] > num[i+1]) {
                num.erase(i, 1);
                --k;
                i = (i > 0) ? i - 2 : -1;
            }
        }

        while(k > 0 && !num.empty() && num.back() != '0') {
            num.pop_back();
            --k;
        }

        size_t start = 0;
        while(start < num.size() && num[start] == '0') {
            ++start;
        }

        string ans = (start < num.size()) ? num.substr(start) : "0";
        return ans.empty() ? "0" : ans;
    }
};
