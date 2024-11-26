// ProblemLink = https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

// 698. Partition to K Equal Sum Subsets

// (TLE) only recurssion used
// TC-> O(2^k*n)
// SC->O(N)

class Solution
{
public:
    bool helper(int i, int bucket, int bucketSum, int reqSum, int k,
                vector<int> &nums, vector<int> &alreadyPicked)
    {

        // baseCase
        if (bucket == k + 1)
            return true;

        if (bucketSum == reqSum)
        {
            return helper(0, bucket + 1, 0, reqSum, k, nums, alreadyPicked);
        }

        if (bucketSum > reqSum || i >= nums.size())
            return false;

        if (alreadyPicked[i] == 1)
        {
            return helper(i + 1, bucket, bucketSum, reqSum, k, nums,
                          alreadyPicked);
        }
        else
        {
            // pick
            bucketSum += nums[i];
            alreadyPicked[i] = 1;
            int opt1 = helper(i + 1, bucket, bucketSum, reqSum, k, nums,
                              alreadyPicked);

            // skip
            bucketSum -= nums[i];
            alreadyPicked[i] = 0;
            int opt2 = helper(i + 1, bucket, bucketSum, reqSum, k, nums,
                              alreadyPicked);

            return opt1 | opt2;
        }
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> alreadyPicked(n, 0);

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % k != 0)
            return false;

        int reqSum = sum / k;

        return helper(0, 1, 0, reqSum, k, nums, alreadyPicked);
    }
};