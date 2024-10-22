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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;
            TreeNode* node;
            for(int i = 0; i < size; ++i) {
                node = q.front();
                sum += node->val;
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(min_heap.size() < k) {
                min_heap.push(sum);
            }
            else if(min_heap.top() < sum) {
                min_heap.pop();
                min_heap.push(sum);
            }
        }
        return min_heap.size() < k ? -1 : min_heap.top();
    }
};
