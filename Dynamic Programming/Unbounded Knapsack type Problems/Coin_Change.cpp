// 1) Max number of ways

int change(int amount, vector<int> &coins)
{
    int n = coins.size();

    vector<vector<uint>> dp(n + 1, vector<uint>(amount + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= amount; j++)
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];

    return dp[n][amount];
}

// 2) Min number of coins

int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();

    vector<vector<uint>> dp(n + 1, vector<uint>(amount + 1, INT_MAX - 1));

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 0; // to prevent 1 + inf

        for (int j = 1; j <= amount; j++)
            if (coins[i - 1] <= j)
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
    }

    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
}
