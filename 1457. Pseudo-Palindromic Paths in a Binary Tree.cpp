
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
    bool isPalindromic(const vector<int>& freq) {
        auto oddNumbers = count_if(cbegin(freq), cend(freq), [](auto const& number){return number % 2 == 1;});

        return oddNumbers < 2;
    }
    void trav(TreeNode* curr, vector<int>& freq, int& pseudoPalindromicPaths) {
        if(curr == nullptr) return;

        ++freq[curr->val];
        if(!curr->left && !curr->right && isPalindromic(freq)){
            ++pseudoPalindromicPaths;
        }

        trav(curr->left, freq, pseudoPalindromicPaths);
        trav(curr->right, freq, pseudoPalindromicPaths);

        --freq[curr->val];
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10);
        int ans = 0;
        trav(root, freq, ans);
        return ans;
    }
};
