
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* first = head;
        ListNode* current = head->next;

        while (current) {
            int sum = 0;

            while (current && current->val != 0) {
                sum += current->val;
                current = current->next;
            }

            if (current) {
                first->val = sum;
                first->next = current->next;
                first = first->next;
                current = current->next;
            }
        }

        return head;
    }
};
