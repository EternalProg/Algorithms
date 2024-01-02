class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {

        vector<vector<int>> result;
        unordered_map<int,int> mp;

        for (int i = 0; i < nums.size(); ++i) {
            int index = mp[nums[i]];

            //  Check if a vector exists for the current index in the result matrix   
            if (index >= result.size()) {
               // If not, add a new vector to the result matrix                
            result.emplace_back();
            }

            // Add the current number to the corresponding vector in the result matrix
            result[index].emplace_back(nums[i]);

            ++mp[nums[i]];
        }
        return result;
/*
        vector<int> freq(nums.size() + 1);
        
        vector<vector<int>> ans;
        for (int c : nums) {
            if (freq[c] >= ans.size()) {
                ans.push_back({});
            }
            
            ans[freq[c]].push_back(c);
            freq[c]++;
        }
        
        return ans;*/
    }
};
