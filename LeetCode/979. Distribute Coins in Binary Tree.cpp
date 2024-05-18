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
    int moves = 0;
    int dfs(TreeNode* curr) {
        if(!curr) return 0;

        int left = dfs(curr->left);
        int right = dfs(curr->right);

        moves += abs(left) + abs(right);
        return left + right + curr->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};
