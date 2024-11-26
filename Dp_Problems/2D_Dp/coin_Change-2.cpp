// ProblemLink = https://leetcode.com/problems/coin-change-ii/

class Solution
{
public:
    int coinHelper(int id, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {

        if (amount == 0)
            return 1;
        if (id >= coins.size() || amount < 0)
            return 0;
        if (dp[id][amount] != -1)
            return dp[id][amount];
        // pickit
        int ans1 = coinHelper(id, amount - coins[id], coins, dp);
        // leaveit
        int ans2 = coinHelper(id + 1, amount, coins, dp);

        return dp[id][amount] = ans1 + ans2;
    }
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        return coinHelper(0, amount, coins, dp);
    }
};