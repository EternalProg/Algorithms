class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;

        priority_queue<int, vector<int>> max_heap;

        for(int numb: nums) {
            max_heap.push(numb);
        }

        for(int i = 0; i < k; ++i) {
            int maxi = max_heap.top();
            max_heap.pop();

            ans += maxi;

            max_heap.push(ceil((double)maxi / 3));
        }

        return ans;
    }
};
