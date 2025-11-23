// Subset Sum

bool isSubsetSum(const vector<int> &arr, int sum)
{
    int n = arr.size();

    // initialize
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // tabulation
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}

// Equal Sum Partition

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum & 1)
        return false;
    sum >>= 1;

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}
