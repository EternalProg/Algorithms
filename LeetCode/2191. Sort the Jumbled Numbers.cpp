class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<long long, int>> map_nums; 
        for(int i = 0; i < nums.size(); ++i) {
            int n = nums[i];
            long long map_num = 0;
            long long place = 1;

            if (n == 0) {
                map_num = mapping[0];
            } else {
                while (n > 0) {
                    map_num += mapping[n % 10] * place;
                    n /= 10;
                    place *= 10;
                }
            }
            map_nums.push_back({map_num, i});
        }

        sort(map_nums.begin(), map_nums.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first < b.first;
        });

        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            ans[i] = nums[map_nums[i].second];
        }

        return ans;
    }
};
