class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;

        for (char ch : s) {
            int char_numb = ch - 'a' + 1;
            while (char_numb > 0) {
                sum += char_numb % 10;
                char_numb /= 10;
            }
        }

        while (k-- > 1) {
            int new_sum = 0;
            while (sum > 0) {
                new_sum += sum % 10;
                sum /= 10;
            }
            sum = new_sum;
        }

        return sum;
    }
};
