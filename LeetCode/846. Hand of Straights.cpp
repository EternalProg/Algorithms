
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> mp;
        for (auto& numb : hand) {
            ++mp[numb];
        }

        for (auto& [numb, freq] : mp) {
            while (mp[numb] > 0) {
                for (int n = numb; n < numb + groupSize; ++n) {
                    if (mp[n] == 0) return false;
                    --mp[n];
                }
            }
        }

        return true;
    }
};
