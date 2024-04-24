/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int result = 0;

    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;

        dfs(root, root->val, root->val);
        return result;
    }

    void dfs(TreeNode* root, int curMax, int curMin) {
        if (root == nullptr) return;

        int possibleResult = max(abs(curMax - root->val), abs(curMin - root->val));
        result = max(result, possibleResult);

        curMax = max(root->val, curMax);
        curMin = min(root->val, curMin);

        dfs(root->left, curMax, curMin);
        dfs(root->right, curMax, curMin);

        return;
    }

};
