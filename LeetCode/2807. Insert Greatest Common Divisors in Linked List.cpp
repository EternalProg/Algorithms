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
    int gcd(int numb1, int numb2) {
        int l = 1;
        int r = min(numb1, numb2); 
        int res = 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (numb1 % mid == 0 && numb2 % mid == 0) {
                res = mid;  
                l = mid + 1; 
            } else {
                r = mid - 1; 
            }
        }
        return res; 
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head->next;
        while(second && first) {
            first->next = new ListNode(__gcd(first->val, second->val));
            first->next->next = second;
            first = second;
            second = second->next;
        }
        return head;
    }
};
