
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        deque<int> indices;
        int minLength = n + 1;

        for (int i = 0; i <= n; ++i) {
            while (!indices.empty() && prefix[i] - prefix[indices.front()] >= k) {
                minLength = min(minLength, i - indices.front());
                indices.pop_front();
            }

            while (!indices.empty() && prefix[indices.back()] >= prefix[i]) {
                indices.pop_back();
            }

            indices.push_back(i);
        }

        return minLength > n ? -1 : minLength;
    }
};
