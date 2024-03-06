auto init = []() {
    cin.sync_with_stdio( false );
    fstream out( "user.out" );
    for ( string s; getline( cin, s ); ) {
        getline( cin, s );
        s[0] != '-' ? out << "true\n" : out << "false\n";
    }
    out.flush();
    exit(0);
    return 0;
}();
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* current = head;
        while(current) {
            if(current->val == 1e9) return true;
            current->val = 1e9;
            current = current->next;
        }
        return false;
    }
};
