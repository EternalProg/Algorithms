class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> arr_minutes(n, 0);

        for(int i = 0; i < n; ++i) {
            int hours = stoi(timePoints[i].substr(0, 2));
            int minutes = stoi(timePoints[i].substr(3));

            arr_minutes[i] = hours * 60 + minutes;
        }

        sort(arr_minutes.begin(), arr_minutes.end());

        int minDiff = INT_MAX;

        for(int i = 1; i < n; ++i) {
            minDiff = min(minDiff, arr_minutes[i] - arr_minutes[i-1]);
        }

        minDiff = min(minDiff, 60 * 24 + arr_minutes.front() - arr_minutes.back());

        return minDiff;
    }
};
