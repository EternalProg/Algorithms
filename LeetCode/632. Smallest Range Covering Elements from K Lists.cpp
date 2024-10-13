class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2, 0);
        int dist = INT_MAX;
        int k = nums.size();

        auto minHeapCompareLambda = [&nums](const pair<int, int>& p1,
                                            const pair<int, int>& p2) {
            return nums[p1.first][p1.second] > nums[p2.first][p2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(minHeapCompareLambda)>
            min_heap(minHeapCompareLambda);

        int max_element = INT_MIN;

        for (int i = 0; i < k; ++i) {
            min_heap.push({i, 0});
            max_element = max(max_element, nums[i][0]);
        }

        while (true) {
            int min_heap_list_index = min_heap.top().first;
            int min_heap_el_index = min_heap.top().second;
            min_heap.pop();

            int mini = nums[min_heap_list_index][min_heap_el_index];

            int cur_dist = abs(max_element - mini);
            if (cur_dist < dist) {
                ans[0] = mini;
                ans[1] = max_element;

                dist = cur_dist;
            }

            if (min_heap_el_index + 1 < nums[min_heap_list_index].size()) {
                min_heap.push({min_heap_list_index, min_heap_el_index + 1});
                max_element =
                    max(max_element,
                        nums[min_heap_list_index][min_heap_el_index + 1]);
            } else {
                return ans;
            }
        }
        return ans;
    }

    static bool minHeapCompare(const pair<int, int>& p1,
                               const pair<int, int>& p2,
                               const vector<vector<int>>& nums) {
        return nums[p1.first][p1.second] > nums[p2.first][p2.second];
    }
};
