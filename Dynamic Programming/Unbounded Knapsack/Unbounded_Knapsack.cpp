int knapsack(const vector<int> &val, const vector<int> &wt, int W)
{
    int n = val.size();

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {

            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(
                    dp[i - 1][j],
                    val[i - 1] + dp[i][j - wt[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][W];
}

// just change dp[i-1][j - wt[i-1]] to dp[i][j - wt[i-1]] in 0-1 knapsack
// as we can take the item multiple times