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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (head && s.find(head->val) != s.end()) {
            ListNode* node_to_delete = head;
            head = head->next;
            delete node_to_delete;
        }

        ListNode* current = head;
        while (current && current->next) {
            if (s.find(current->next->val) != s.end()) {
                ListNode* next_node = current->next->next;
                delete current->next;
                current->next = next_node;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};
