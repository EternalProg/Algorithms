class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int numb: nums) {
            int indx = abs(numb) - 1;
            if(nums[indx] < 0) 
                ans.push_back(indx + 1);
            else 
                nums[indx] = -nums[indx];
        }
        return ans;
    }
};
