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
    bool dfs(TreeNode* curr1, TreeNode* curr2) {
        if (!curr1 && !curr2) return true;

        if (!curr1 || !curr2) return false;

        if (curr1->val != curr2->val) return false;

        bool noFlip = dfs(curr1->left, curr2->left) && dfs(curr1->right, curr2->right);
        bool flip = dfs(curr1->left, curr2->right) && dfs(curr1->right, curr2->left);

        return noFlip || flip;
    }
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        return dfs(r1, r2);
    }
};
