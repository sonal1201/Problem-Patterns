// ProblemLink =https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/

class Solution
{
#define ll long long
private:
    ll getMaxDamage(vector<ll> &dp, map<int, int> &frequencyMap,
                    vector<int> &uniquePowers, int i)
    {
        if (i == uniquePowers.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        // Option 1: Skip the current element
        ll skip = getMaxDamage(dp, frequencyMap, uniquePowers, i + 1);
        // Option 2: Take the current element
        ll take = 0;
        int nextIndex = i + 1;

        // Skip over all elements in uniquePowers whose values are within a difference of 2 from uniquePowers[index].

        while (nextIndex < uniquePowers.size() &&
               uniquePowers[nextIndex] - uniquePowers[i] <= 2)
        {
            nextIndex++;
        }
        take = ((1ll) * frequencyMap[uniquePowers[i]] * uniquePowers[i]) +
               getMaxDamage(dp, frequencyMap, uniquePowers, nextIndex);
        return dp[i] = max(take, skip);
    }

public:
    long long maximumTotalDamage(vector<int> &power)
    {
        map<int, int> frequencyMap;
        vector<int> uniquePowers;
        // frequency map and unique powers list
        for (auto p : power)
        {
            frequencyMap[p]++;
        }
        for (auto it : frequencyMap)
        {
            uniquePowers.push_back(it.first);
        }
        // Initialize DP array with -1
        vector<ll> dp(frequencyMap.size(), -1);
        // Start the recursive function
        return getMaxDamage(dp, frequencyMap, uniquePowers, 0);
    }
};