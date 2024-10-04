class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans = 0;
        sort(skill.begin(), skill.end());

        int l = 0;
        int r = skill.size()-1;
        int prevSum = skill[l] + skill[r];

        while(l < r) {
            int sum = skill[l] + skill[r];
            if(prevSum != sum ) return -1;
            ans += skill[l] * skill[r];
            ++l;
            --r;
        }
        return ans;
    }
};
