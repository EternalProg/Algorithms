   
// Difficult problem
// https://youtu.be/Uz2iNhjGGm0
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/solutions/409009/java-c-python-dp-solution/

class Solution {
public:
/*
    int dp[50001];

    int findMaxProfit(vector<vector<int>>& jobs, vector<int>&start, int n, int id) {
        if(id == n) return 0;

        if(dp[id] != -1) return dp[id];

        int nextIndex = lower_bound(start.begin(), start.end(), jobs[id][1]) - start.begin();

        int maxProfit = max(findMaxProfit(jobs, start, n, id + 1),
                        jobs[id][2] + findMaxProfit(jobs, start, n, nextIndex));
        return dp[id] = maxProfit;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < profit.size(); ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        for(int i = 0; i < profit.size(); ++i) {
            startTime[i] = jobs[i][0];
        }

        return findMaxProfit(jobs, startTime, profit.size(), 0);
    }
*/
    public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};


