
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0, right = 0, cost = 0, maxLength = 0;
        
        while (right < s.size()) {
            cost += abs(s[right] - t[right]);
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        
        return maxLength;
    }
};
