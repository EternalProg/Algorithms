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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> umap;
        for (auto& d : descriptions) {
            TreeNode* parent = umap.count(d[0]) ? umap[d[0]] : new TreeNode(d[0]);
            TreeNode* child = umap.count(d[1]) ? umap[d[1]] : new TreeNode(d[1]);
            if (d[2]) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            umap[d[0]] = parent;
            umap[d[1]] = child;
        }
        for (auto& d : descriptions) {
            umap.erase(d[1]);
        }
        return umap.begin()->second;
    }
};
