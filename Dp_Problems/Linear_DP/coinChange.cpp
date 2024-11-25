// Problem Link - https: // leetcode.com/problems/coin-change/description/

class Solution
{
public:
    int dp[10004];

    int coinHelper(vector<int> &coins, int amount)
    {
        if (amount <= 0)
        {
            return 0;
        }
        if (dp[amount] != -1)
            return dp[amount];
        int ans = INT_MAX;
        for (int coin : coins)
        {
            if (amount - coin >= 0)
            {
                ans = min(1LL + coinHelper(coins, amount - coin), ans + 0LL);
            }
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        int ans = coinHelper(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};