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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        queue<TreeNode*> q;
        q.push(root);
        int cur_depth = 0;

        while(!q.empty()) {
            int size = q.size();

            ++cur_depth;
            while(size--) {
                TreeNode* curr = q.front();
                q.pop();

                if(cur_depth != depth-1) {
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                else {
                    TreeNode *node1 = new TreeNode(val), 
                             *node2 = new TreeNode(val);
                    node1->left = curr->left;
                    node2->right = curr->right;

                    curr->left = node1;
                    curr->right = node2;
                }
            }
        }
        return root;
    }
};
