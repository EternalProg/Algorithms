
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        ListNode* current = head;

        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (current && top <= bottom && left <= right) {

            // left -> right
            for (int c = left; c <= right && current; ++c) {
                ans[top][c] = current->val;
                current = current->next;
            }
            ++top;

            // top -> bottom
            for (int r = top; r <= bottom && current; ++r) {
                ans[r][right] = current->val;
                current = current->next;
            }
            --right;

            // right -> left
            for (int c = right; c >= left && current; --c) {
                ans[bottom][c] = current->val;
                current = current->next;
            }
            --bottom;

            // bottom -> top
            for (int r = bottom; r >= top && current; --r) {
                ans[r][left] = current->val;
                current = current->next;
            }
            ++left;
        }

        return ans;
    }
};
