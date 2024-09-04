class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacles_position;
        for (auto& v : obstacles) {
            obstacles_position.insert(to_string(v[0]) + " " + to_string(v[1]));
        }

        int ans = 0;
        int x = 0;
        int y = 0;

        vector<pair<int, int>> v_dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;

        for (int command : commands) {
            if (command == -2) {
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                dir = (dir + 1) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int next_x = x + v_dir[dir].first;
                    int next_y = y + v_dir[dir].second;

                    if (obstacles_position.find(to_string(next_x) + " " +
                                                to_string(next_y)) !=
                        obstacles_position.end()) {
                        break;
                    }

                    x = next_x;
                    y = next_y;
                }

                ans = max(ans, x * x + y * y);
            }
        }
        return ans;
    }
};
