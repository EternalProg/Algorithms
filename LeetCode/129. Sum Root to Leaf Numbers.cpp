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
 /*
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* root, int cur) {
        if(!root) return 0;
        cur = cur * 10 + root->val;
        if(!root->left && !root->right) return cur;
        return dfs(root->left, cur) + dfs(root->right, cur);
    }
};
*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 0});
        int ans = 0;

        while(!st.empty()) {
            auto [root, cur] = st.top();
            st.pop();
            cur = cur * 10 + root->val;
            if(!root->left && !root->right) ans += cur;
            if(root->left) st.push({root->left, cur});
            if(root->right) st.push({root->right, cur});
        }
        return ans;
    }
};
