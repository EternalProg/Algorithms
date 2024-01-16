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
    void postorderTrav(TreeNode* curr, vector<int>& v) {
        if(curr == nullptr)
            return;

        postorderTrav(curr->left, v);
        postorderTrav(curr->right, v);
        v.push_back(curr->val);

    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderTrav(root, result);

        return result;
    }
};
