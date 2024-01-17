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
    int trav(TreeNode* curr, int& sum) {
        if(!curr) return 0;

        int left = max(0, trav(curr->left, sum));
        int right = max(0, trav(curr->right, sum));

        int localSum = curr->val + left + right;

        sum = max(sum, localSum);

        return curr->val + max(right, left);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        trav(root, sum);
        return sum;
    }
};
