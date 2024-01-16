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
    void preOrderTrav(TreeNode* curr, vector<int>& preOrder) {
        if(curr == nullptr)
            return;
        preOrder.push_back(curr->val);
        preOrderTrav(curr->left, preOrder);
        preOrderTrav(curr->right, preOrder);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preOrderTrav(root, result);
        return result;
    }
};
