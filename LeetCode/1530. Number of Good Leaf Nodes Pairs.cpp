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
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }

private:
    std::vector<int> dfs(TreeNode* node, int distance, int& ans) {
        if (node == nullptr) {
            return {};
        }
        if (node->left == nullptr && node->right == nullptr) {
            return {1};
        }

        std::vector<int> left = dfs(node->left, distance, ans);
        std::vector<int> right = dfs(node->right, distance, ans);
        std::vector<int> ret;

        for (int l : left) {
            for (int r : right) {
                if (l + r <= distance) {
                    ans++;
                }
            }
            if (l + 1 < distance) {
                ret.push_back(l + 1);
            }
        }

        for (int r : right) {
            if (r + 1 < distance) {
                ret.push_back(r + 1);
            }
        }

        return ret;
    }
};
