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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(!node.first->left && !node.first->right && node.second == true)
                ans += node.first->val;
            
            if(node.first->left) q.push({node.first->left, true});
            if(node.first->right) q.push({node.first->right, false});
        }
        return ans;
    }
};
