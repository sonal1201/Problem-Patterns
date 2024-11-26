class Solution
{
public:
    bool equalChecker(int i, vector<vector<int>> &dp, vector<int> &nums,
                      int target)
    {

        if (target == 0)
            return true;

        if (i >= nums.size() || target < 0)
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        // pick
        bool pick = false;
        if (target >= nums[i])
        {
            pick = equalChecker(i + 1, dp, nums, target - nums[i]);
        }

        // not pick
        bool notPick = equalChecker(i + 1, dp, nums, target);

        return dp[i][target] = pick || notPick;
    }

    bool canPartition(vector<int> &nums)
    {

        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
        {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

        return equalChecker(0, dp, nums, target);
    }
};