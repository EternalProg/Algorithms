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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;

        int sum = 0;

        if(root->val >= low && root->val <= high)
            sum += root->val;

        if(root->left && root->val > low)
            sum += rangeSumBST(root->left, low, high);

        if(root->right && root->val < high)
            sum += rangeSumBST(root->right, low, high);
        return sum;
    }
};

// https://leetcode.com/problems/range-sum-of-bst/solutions/4527527/c-easy-solution-with-explain/
