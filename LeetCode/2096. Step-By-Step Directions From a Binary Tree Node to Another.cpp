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
    TreeNode* getLCA(TreeNode* root, int start, int dest) {
        if(!root) return NULL;
        
        if(root->val == start || root->val == dest) return root;
        
        TreeNode* left = getLCA(root->left, start, dest);
        TreeNode* right = getLCA(root->right, start, dest);
        
        if(left && right) return root;
        
        return left ? left : right;
    }
    
    bool traverse(TreeNode* root, string& path, int val) {
        if(!root) return false;
        
        if(root->val == val) return true;
        
        path.push_back('L');
        if(traverse(root->left, path, val)) return true;
        path.pop_back(); 

        path.push_back('R');
        if(traverse(root->right, path, val)) return true;
        path.pop_back();

        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* lca = getLCA(root, startValue, destValue);
        
        string lca_to_start = "", lca_to_dest = "";
        
        traverse(lca, lca_to_start, startValue);
        traverse(lca, lca_to_dest, destValue);
        
        for(auto& c : lca_to_start) c = 'U';
       
        return lca_to_start + lca_to_dest;
    }
};
