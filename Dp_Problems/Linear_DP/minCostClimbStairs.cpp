// ProblemLink - https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int dp[1004];
    int stairsHelper(int i, vector<int>& cost) {
        // basecase
        if (i >= cost.size())
            return 0;

        if(dp[i]!=-1) return dp[i];

        int start0 = cost[i] + stairsHelper(i+1, cost);
        int start1 = cost[i] + stairsHelper(i+2, cost);

        return dp[i] = min(start0, start1);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return min(stairsHelper(0, cost),stairsHelper(1, cost));
    }
};