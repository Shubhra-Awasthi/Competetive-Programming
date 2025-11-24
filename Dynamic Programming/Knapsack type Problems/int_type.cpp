// Count of Subsets with given Sum
int canPartition(vector<int> &nums, int sum)
{
    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][sum];
}

// Minimum Subset Sum Difference
int minDifference(vector<int> &arr)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    int maxi_sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum / 2; j++)
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                if (dp[i][j])
                    maxi_sum = max(maxi_sum, j);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }

    return abs(maxi_sum - (sum - maxi_sum));
}