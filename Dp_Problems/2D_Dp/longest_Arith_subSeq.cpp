// ProblemLink =https://leetcode.com/problems/longest-arithmetic-subsequence/

class Solution
{
public:
    int dp[1004][1004];
    int solve(int i, int diff, vector<int> &nums)
    {
        if (i < 0)
            return 0;

        // added 501 because we dont want to go neg
        if (dp[i][diff + 501] != -1)
            return dp[i][diff + 501];

        int ans = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] - nums[j] == diff)
            {
                ans = max(ans, 1 + solve(j, diff, nums));
            }
        }

        return dp[i][diff + 501] = ans;
    }

    int longestArithSeqLength(vector<int> &nums)
    {

        memset(dp, -1, sizeof(dp));

        if (nums.size() <= 2)
            return nums.size();
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums));
            }
        }
        return ans;
    }
};