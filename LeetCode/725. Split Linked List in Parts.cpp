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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* current = head;
        while(current) {
            ++size;
            current = current->next;
        }

        int base_size = size / k;
        int extra_size = size % k;

        current = head;
        vector<ListNode*> res(k, nullptr);
        for(int i = 0; i < k && current; ++i) {
            res[i] = current;
            int current_part_size = base_size + (i < extra_size ? 1 : 0);

            for(int j = 1; j < current_part_size; ++j) {
                current = current->next;
            }

            head = current->next;
            current->next = nullptr;
            current = head;
        }
        return res;
    }
};
