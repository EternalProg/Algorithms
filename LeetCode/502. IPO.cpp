class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); ++i) {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitQueue;
        int j = 0;

        for (int i = 0; i < k; ++i) {
            while (j < projects.size() && projects[j].first <= w) {
                maxProfitQueue.push(projects[j].second);
                ++j;
            }

            if (!maxProfitQueue.empty()) {
                w += maxProfitQueue.top();
                maxProfitQueue.pop();
            } else {
                break;
            }
        }

        return w;
    }
};
