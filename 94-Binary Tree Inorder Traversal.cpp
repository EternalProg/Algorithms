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
    void inorderTrav(TreeNode* curr, vector<int>& v) {
        if(curr == nullptr)
            return;

        inorderTrav(curr->left, v);
        v.push_back(curr->val);
        inorderTrav(curr->right, v);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTrav(root, result);

        return result;
    }
};
