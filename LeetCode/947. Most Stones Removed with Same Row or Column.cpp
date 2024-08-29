class Solution {
public:
    void dfs(vector<vector<int>>& stones, unordered_map<int, vector<int>>& rows,
             unordered_map<int, vector<int>>& cols, int cur_indx,
             unordered_set<int>& visited) {
        visited.insert(cur_indx);
        int row = stones[cur_indx][0];
        int col = stones[cur_indx][1];

        for (int neighbor : rows[row]) {
            if (!visited.count(neighbor)) {
                dfs(stones, rows, cols, neighbor, visited);
            }
        }

        for (int neighbor : cols[col]) {
            if (!visited.count(neighbor)) {
                dfs(stones, rows, cols, neighbor, visited);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> cols;
        for (int i = 0; i < stones.size(); ++i) {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }

        unordered_set<int> visited;

        int components = 0;

        for (int i = 0; i < stones.size(); ++i) {
            if (!visited.count(i)) {
                dfs(stones, rows, cols, i, visited);
                ++components;
            } 
        }
        return stones.size() - components;
    }
};
