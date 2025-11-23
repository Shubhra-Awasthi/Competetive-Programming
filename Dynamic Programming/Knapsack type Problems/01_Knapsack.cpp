// 1) Recursive + Memoization:

static int dp[N][W]; // initialize with -1 and put N and W acc to question

int knapsack(const vector<int> &wt, const vector<int> &val, int W, int n)
{

    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (dp[n - 1] <= W)
        return dp[n][W] = max(val[n - 1] + knapsack(wt, val, W - dp[n - 1], n - 1), knapsack(wt, val, W, n - 1));
    else
        return dp[n][W] = knapsack(wt, val, W, n - 1);
}

// 2) Tabulation: Top down
int knapsack(const vector<int> &wt, const vector<int> &val, int W, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}