// ProblemLink = https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int price : prices)
        {
            mini = min(mini, price);
            maxi = max(maxi, price - mini);
        }
        return maxi;
    }
};