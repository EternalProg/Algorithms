
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int maxDistance = 0;
        int minDistance = INT_MAX;
        ListNode* current = head;
        int prev_val = INT_MAX;
        int prev_critical_point = -1;
        int i = 0;
        int first_critical_point = -1;

        while (current && current->next) {
            if (i > 0) {
                if ((prev_val < current->val &&
                     current->val > current->next->val) ||
                    (prev_val > current->val &&
                     current->val < current->next->val)) {

                    if (first_critical_point == -1) {
                        first_critical_point = i;
                    } else {
                        minDistance = min(minDistance, i - prev_critical_point);
                        maxDistance =
                            max(maxDistance, i - first_critical_point);
                    }

                    prev_critical_point = i;
                }
            }
            prev_val = current->val;
            current = current->next;
            ++i;
        }

        if (first_critical_point == prev_critical_point) {
            return {-1, -1};
        }

        return {minDistance, maxDistance};
    }
};
