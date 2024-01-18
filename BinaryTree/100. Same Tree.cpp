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
    bool trav(TreeNode* first, TreeNode* second) {
        if(!first && !second) return true;
        else if(!first && second || !second && first) return false;
        else if(first->val == second->val) {
            bool left = trav(first->left, second->left);
            bool right = trav(first->right, second->right);

            return left && right;
        }
        else return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return trav(p, q);
    }
};
