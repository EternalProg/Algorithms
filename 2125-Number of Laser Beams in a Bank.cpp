class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int result = 0;
        int prev = 0;

        for (const string& row : bank) {
            int beams = count(row.begin(), row.end(), '1');
            if(beams) {
                result += prev * beams;
                prev = beams;
            }
        }
 
        return result;
    }
};
