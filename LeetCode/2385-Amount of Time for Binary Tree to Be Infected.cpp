class Solution {
public:

    /*
        The questions becomes very easy once we convert it to a graph

        Doing a one pass DFS is difficult

        Idea: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/discuss/2465369/BFS-vs.-DFS

        return a pair {depth to a leaf, depth to the start node}
    */
    int src, ans;

    pair<int, int> dfs(TreeNode *node) {
        if (node == NULL) {
            return {0, -1};
        }

        pair<int, int> l = dfs(node -> left);
        pair<int, int> r = dfs(node -> right);

        // If the left subtree contains the start node,
        // depth to start node increases by 1
        // update height of node appropriately
        // Main : Update answer to be height of right subtree + depth to start
        if (l.second != -1) {
            ans = max(ans, l.second + r.first);
            return {max(l.first, r.first) + 1, l.second + 1};
        }

        // If the right subtree contains the start node,
        // depth to start node increases by 1
        // update height of node appropriately
        // Main : Update answer to be height of left subtree + depth to start
        if (r.second != -1) {
            ans = max(ans, r.second + l.first);
            return {max(l.first, r.first) + 1, r.second + 1};
        }


        // IF the current node is the start node, update answer with
        // max heights of the left and the right subtrees
        if (node -> val == src) {
            ans = max(ans, max(l.first, r.first));
            return {max(l.first, r.first) + 1, 1};
        }

        // If neither left nor right contains start, and this node is also not the start,
        // return height of node, -1
        return {max(l.first, r.first) + 1, -1};
    }

    int amountOfTime(TreeNode* root, int start) {
        src = start;
        ans = 0;
        pair<int, int> p = dfs(root);
        return ans;
    }
};
