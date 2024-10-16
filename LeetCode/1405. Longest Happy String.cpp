
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int, char>> max_heap;

        if (a > 0)
            max_heap.push({a, 'a'});
        if (b > 0)
            max_heap.push({b, 'b'});
        if (c > 0)
            max_heap.push({c, 'c'});

        while (!max_heap.empty()) {
            int count = max_heap.top().first;
            char ch = max_heap.top().second;
            max_heap.pop();

            if (res.size() >= 2 && res[res.size() - 1] == res[res.size() - 2] && res[res.size() - 1] == ch) {
                if (!max_heap.empty()) {
                    int count2 = max_heap.top().first;
                    char ch2 = max_heap.top().second;
                    max_heap.pop();

                    res.push_back(ch2);
                    --count2;
                    
                    if (count2 > 0) {
                        max_heap.push({count2, ch2});
                    }

                    max_heap.push({count, ch});
                } else {
                    break;
                }
            } else {
                res.push_back(ch);
                --count;

                if (count > 0) {
                    max_heap.push({count, ch});
                }
            }
        }

        return res;
    }
};
