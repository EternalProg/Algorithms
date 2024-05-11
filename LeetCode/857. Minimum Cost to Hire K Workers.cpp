class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> workerRatio(n);
    for (int i = 0; i < n; ++i) {
      workerRatio[i] = {(double)wage[i] / quality[i], quality[i]};
    }
    sort(workerRatio.begin(), workerRatio.end());

    priority_queue<int> qualityMaxHeap;
    double minCost = 1e9;
    int totalQuality = 0;

    for (auto& [ratio, workerQuality] : workerRatio) {
      totalQuality += workerQuality;
      qualityMaxHeap.push(workerQuality);

      if (qualityMaxHeap.size() == k) {
        minCost = min(minCost, totalQuality * ratio);
        totalQuality -= qualityMaxHeap.top();
        qualityMaxHeap.pop();
      }
    }
    return minCost;
  }
};

// https://algo.monster/liteproblems/857
