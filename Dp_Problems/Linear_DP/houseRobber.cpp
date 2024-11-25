ProblemLink = https://leetcode.com/problems/house-robber/description/

class Solution
{
public:
    int dp[104];

    int robHelper(int i, vector<int> &nums)
    {

        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int rob1 = 0;
        int rob2 = 0;

        // pick it
        rob1 += nums[i];
        rob1 += robHelper(i + 2, nums);

        // leave it
        rob2 += robHelper(i + 1, nums);

        return dp[i] = max(rob1, rob2);
    }
    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));

        return robHelper(0, nums);
    }
};