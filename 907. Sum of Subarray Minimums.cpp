class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        stack<pair<int,int>> sLeft, sRight;

        for(int i = 0; i < n; ++i) {
            int cnt = 1;
            while(!sLeft.empty() && sLeft.top().first > arr[i]) {
                cnt += sLeft.top().second;
                sLeft.pop();
            }
            sLeft.push({arr[i], cnt});
            left[i] = cnt;
        }

        for(int i = n-1; i >= 0; --i) {
            int cnt = 1;
            while(!sRight.empty() && sRight.top().first >= arr[i]) {
                cnt += sRight.top().second;
                sRight.pop();
            }
            sRight.push({arr[i], cnt});
            right[i] = cnt;
        }

        int ans = 0, mod = 1e9 +7;
        for(int i = 0; i < n; ++i) {
            ans = (ans + (arr[i] * (long long)(left[i] * right[i])% mod)% mod) % mod;
        }
        return ans;
    }
};

// https://youtu.be/5Hag64mLXac
