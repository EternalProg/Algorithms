class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = 0;
        for (int ch : chalk) {
            sum += ch;
        }

        while (sum < k) {
            k -= sum;
        }

        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i])
                return i;
            k -= chalk[i];
        }

        return k;
    }

    const int SPEED = []() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return 0;
    }();
};
