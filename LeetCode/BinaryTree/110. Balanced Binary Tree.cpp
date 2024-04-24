
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
    int isBalancedHelper(TreeNode* curr) {
        if (!curr) return 0;

        int leftDepth = isBalancedHelper(curr->left);
        if (leftDepth == -1) return -1;

        int rightDepth = isBalancedHelper(curr->right);
        if (rightDepth == -1) return -1;

        if (abs(leftDepth - rightDepth) <= 1) {
            return 1 + max(leftDepth, rightDepth);
        } else {
            return -1; 
        }
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedHelper(root) != -1;
    }
};
