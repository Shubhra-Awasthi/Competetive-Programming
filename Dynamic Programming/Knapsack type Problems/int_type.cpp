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

// Count the number of subset with a given difference
int countPartitions(vector<int> &arr, int diff)
{
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);

    if (diff > sum || (sum + diff) & 1)
        return 0;

    int k = (sum + diff) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][k];

    // if there are 0's in the array then cnt them, remove them then return dp[n][k] * (2^count_of_0's)
}

// Target sum by adding + and - before elements
int findTargetSumWays(vector<int> &nums, int tar)
{
    // handling zeroes
    int zeros = 0;
    vector<int> temp;
    for (int n : nums)
        if (n)
            temp.push_back(n);
        else
            zeros++;

    nums = temp;
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if ((tar + sum) & 1 || abs(tar) > sum)
        return 0;

    int k = (tar + sum) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][k] * (1 << zeros);
}