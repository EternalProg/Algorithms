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
    unordered_map<int, pair<int,int>> mp;
    int depth(TreeNode* cur, int cur_h){
        if(cur == NULL){
            return -1;
        }
        int left = depth(cur->left, cur_h + 1);
        int right = depth(cur->right, cur_h + 1);
        int cur_d = max(left, right) + 1;
        mp[cur->val] = {cur_h, cur_d};
        return cur_d;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        depth(root, 0);
        unordered_map<int, vector<int>> nei;

        for(auto& [key, val] : mp){
            int h = val.first;
            int d = val.second;
            nei[h].push_back(d);
            sort(nei[h].begin(), nei[h].end(), greater<int>());
            if(nei[h].size() > 2){
                nei[h].pop_back();
            }
        }


        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i++){
            int h = mp[queries[i]].first;
            int d = mp[queries[i]].second;
            if(nei[h].size() == 1){
                res[i] = h - 1;
            }else{
                if(nei[h][0] == d){
                    res[i] = h + nei[h][1];
                }else{
                    res[i] = h + nei[h][0];
                }
            }
        }

        return res;
        
    }
};
