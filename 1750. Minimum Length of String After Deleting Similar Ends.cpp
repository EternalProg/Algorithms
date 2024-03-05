const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
<<<<<<< HEAD

=======
>>>>>>> 93b9e70 (Marz 5, 2024. Medium problem: Two pointer, String.)
class Solution {
public:
    int minimumLength(string s) {
        int l = 0, h = s.size()-1;

        while(l < h && s[l] == s[h]) {
            char ch = s[l];
            while(l <= h && s[l] == ch) {
                ++l;
            }
            while(h >= l && s[h] == ch) {
                --h;
            }
        }
        
        return h - l + 1;
    }
};
