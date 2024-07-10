const int SPEED = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    bool is_move_to_child_folder(const string& move) {
        return move[0] != '.';
    }
    bool is_move_to_parent_folder(const string& move) {
        return move[0] == '.' && move[1] == '.';
    }
    int minOperations(vector<string>& logs) {
        int res = 0;
        for(auto& move: logs) {
            if(is_move_to_child_folder(move)) {
                ++res;
            }
            else if(is_move_to_parent_folder(move) && res > 0) {
                --res;
            }
        }
        return res;
    }
};
