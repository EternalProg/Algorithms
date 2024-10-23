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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr; 
        root->val = 0;
        queue<pair<TreeNode*, TreeNode*>> q;
        if(root->left) {
            q.push({root->left, root});
        }
        if(root->right) {
            q.push({root->right, root});
        }

        while(!q.empty()) {
            int size = q.size();
            unordered_map<TreeNode*, int> mp;
            int sum = 0;

            for(int i = 0; i < size; ++i) {
                TreeNode* node = q.front().first;
                TreeNode* parent = q.front().second;
                q.pop();

                mp[parent] += node->val;
                sum += node->val;

                if(node->left) {
                    q.push({node->left, node});
                }
                if(node->right) {
                    q.push({node->right, node});
                }
            }

            for(auto& [parent, sumOfChildren]: mp) {
                if (parent->left) {
                    parent->left->val = sum - sumOfChildren;
                }
                if (parent->right) {
                    parent->right->val = sum - sumOfChildren;
                }
            }
        }
        return root;
    }
};
