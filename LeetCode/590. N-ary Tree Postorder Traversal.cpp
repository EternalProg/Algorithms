/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void trav(Node* curr, vector<int>& ans) {
        if(!curr) return;

        for(Node* child: curr->children) {
            trav(child, ans);
        }
        ans.push_back(curr->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        trav(root, ans);
        return ans;
    }
};
