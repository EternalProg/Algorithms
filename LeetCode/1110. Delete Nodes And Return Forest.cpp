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
    vector<TreeNode*> Ans;
    unordered_set<int>s;
    
    TreeNode* f(TreeNode* a)
    {
        if(!a)return nullptr;

        a->left=f(a->left);
        a->right=f(a->right);

        if(!s.count(a->val))  return a;

        if(a->left )Ans.push_back(a->left);
        if(a->right)Ans.push_back(a->right);
        return nullptr;    
    }
public:
    vector<TreeNode*> delNodes(TreeNode* a, vector<int>& v) {
        s.insert(v.begin(),v.end());
        f(a);
        if(!s.count(a->val))Ans.push_back(a);
        return Ans;
    }
};
