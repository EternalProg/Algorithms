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
/* // speed up
#pragma GCC optimize("O3", "unroll-loops")
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
*/
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* current = list1;
        int i = 0;
        while(current) {
            if(i == a-1) {
                ListNode* start = current;
                ListNode* tmp = list2;
                current = current->next;
                ++i;
                while(i != b+1) {
                    ListNode* n = current;
                    current = current->next;
                    //delete n; //without leak of memory
                    ++i;
                }
                start->next = tmp;
                while(tmp->next) {
                    tmp = tmp->next;
                }
                tmp->next = current;
                return list1;
            }
            current = current->next;
            ++i;
        }
        return list1;
    }
};
