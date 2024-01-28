class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int result = 0;

        for (int left = 0; left < cols; ++left) {
            vector<int> row_sums(rows, 0);

            for (int right = left; right < cols; ++right) {
                for (int i = 0; i < rows; ++i) {
                    row_sums[i] += matrix[i][right];
                }

                unordered_map<int, int> sum_count;
                int current_sum = 0;
                sum_count[0] = 1;

                for (int i = 0; i < rows; ++i) {
                    current_sum += row_sums[i];
                    result += sum_count[current_sum - target];
                    sum_count[current_sum]++;
                }
            }
        }

        return result;
    }
};
