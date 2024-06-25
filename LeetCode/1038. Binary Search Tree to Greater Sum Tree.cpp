
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
    int s(TreeNode* root, int val) {
        if(!root) return val;

        val = s(root->right, val);
        root->val += val;
        
        return s(root->left, root->val);
    }
    TreeNode* bstToGst(TreeNode* root) {
        s(root, 0);
        return root;
    }
};
