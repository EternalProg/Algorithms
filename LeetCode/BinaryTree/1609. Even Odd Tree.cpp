
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
const int ZERO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int index = 0;
        while (!q.empty()) {
            int size = q.size();
            int prev = index % 2 == 0 ? INT_MIN : INT_MAX;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (index % 2 == 0) {
                    if (node->val % 2 == 0 || node->val <= prev)
                        return false;
                } else {
                    if (node->val % 2 != 0 || node->val >= prev)
                        return false;
                }
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                prev = node->val;
            }
            ++index;
        }
        return true;
    }
};
