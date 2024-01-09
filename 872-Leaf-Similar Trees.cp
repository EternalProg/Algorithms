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
    void traversal(TreeNode* curr, vector<int> &result) {
        if(curr == nullptr)
            return;
        if(curr->left == nullptr && curr->right == nullptr)
            result.push_back(curr->val);

        traversal(curr->left, result);
        traversal(curr->right, result);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        traversal(root1, leaves1);
        traversal(root2, leaves2);

        return leaves1 == leaves2;
    }
};

// Detailed solution: https://leetcode.com/problems/leaf-similar-trees/solutions/4534082/beats-100-easiest-and-most-understandable-c-solution/
