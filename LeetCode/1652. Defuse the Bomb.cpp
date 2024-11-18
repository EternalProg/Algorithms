class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0)
            return result;

        int start = 0;
        int end = 0;

        if (k > 0) {
            start = 1;
            end = k;
        } else {
            start = n + k;
            end = n - 1;
        }

        int windowSum = 0;
        for (int i = start; i <= end; ++i) {
            windowSum += code[i % n];
        }

        for (int i = 0; i < n; ++i) {
            result[i] = windowSum;

            windowSum -= code[start % n];
            start++;
            end++;
            windowSum += code[end % n];
        }

        return result;
    }
};
