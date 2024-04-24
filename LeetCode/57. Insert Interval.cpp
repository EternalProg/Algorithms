#pragma GCC optimize("O3", "unroll-loops")
class Solution {
 public:
  // Method to insert a new interval into the list of existing intervals and
  // then merge them
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    // Add the new interval to the end of the intervals vector
    intervals.emplace_back(newInterval);
    // Merge the updated list of intervals
    return merge(intervals);
  }

  // Method to merge overlapping intervals in a list
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Sort the intervals in ascending order based on the start times
    sort(intervals.begin(), intervals.end());

    // This will hold the merged intervals
    vector<vector<int>> mergedIntervals;

    // Add the first interval to the merged list as a starting point
    mergedIntervals.emplace_back(intervals[0]);

    // Iterate through the intervals starting with the second interval
    for (int i = 1; i < intervals.size(); ++i) {
      // If the current interval does not overlap with the last interval in the
      // merged list, it means we can add it as a new entry to the merged list
      if (mergedIntervals.back()[1] < intervals[i][0]) {
        mergedIntervals.emplace_back(intervals[i]);
      } else {
        // If they overlap, merge the current interval with the last interval of
        // the merged list by updating the ending time of the last interval in
        // mergedList
        mergedIntervals.back()[1] =
            max(mergedIntervals.back()[1], intervals[i][1]);
      }
    }

    // Return the list of merged intervals
    return mergedIntervals;
  }
};
