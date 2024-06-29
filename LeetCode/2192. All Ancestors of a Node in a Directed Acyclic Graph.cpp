class Solution {
public:
    void dfs(int ancestor, int ver, vector<vector<int>>& graph,
             vector<vector<int>>& ans, vector<bool>& vis) {
        vis[ver] = 1;
        for (int child : graph[ver]) {
            if (!vis[child]) {
                ans[child].push_back(ancestor);
                dfs(ancestor, child, graph, ans, vis);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n), graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, 0);
            dfs(i, i, graph, ans, vis);
        }
        return ans;
    }
};
