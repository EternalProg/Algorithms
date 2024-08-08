class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        vector<vector<int>> result;
        result.reserve(rows * cols);
        vector<int> directions = {0, 1, 0, -1, 0}; // [right, down, left, up]
        int steps = 1;
        int r = rStart, c = cStart;

        result.push_back({r, c});

        while (result.size() < rows * cols) {
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < steps; ++j) {
                    r += directions[i];
                    c += directions[i + 1];

                    if (r >= 0 && r < rows && c >= 0 && c < cols) {
                        result.push_back({r, c});
                    }
                }
                steps += i % 2 == 1;
            }
        }

        return result;
    }
};
