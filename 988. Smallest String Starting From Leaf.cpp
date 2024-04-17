
class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>> q;
        q.push({root, ""});
        string ans = "";

        while(!q.empty()) {
            auto [curr, str] = q.front();
            q.pop();

            str.insert(str.begin(), 'a' + curr->val);

            if(!curr->left && !curr->right) {
                if(ans == "" || str < ans) ans = str;
            }
            if(curr->left) q.push({curr->left, str});
            if(curr->right) q.push({curr->right, str});
        }
        return ans;
    }
};
