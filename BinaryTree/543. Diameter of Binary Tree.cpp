
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
    int height(TreeNode* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
// const int ZERO = []() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     return 0;
// }();
// class Solution {
// public:
//     pair<int,int> solve(TreeNode *root){
//         if(root==NULL){
//             pair<int,int>temp = make_pair(0,0);
//             return temp;
//         }
//
//         pair<int,int>left= solve(root->left);
//         pair<int,int>right =solve(root->right);
//
//         int op1=left.first;
//         int op2=right.first;
//         int op3 = left.second +right.second;
//
//         pair<int,int>ans;
//         ans.first= max(op1 , max(op2, op3));
//         ans.second = max(left.second ,right.second) +1;
//
//         return ans;
//
//
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         return solve(root).first;
//         
//     }
// };

// https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree/
