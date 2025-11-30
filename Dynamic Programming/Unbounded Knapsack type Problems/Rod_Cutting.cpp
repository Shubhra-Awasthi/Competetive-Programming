// Rod cutting -> len = wt, price = val, W = total length of rod
int cutRod(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int j = 1; j <= n; j++)
        if (i <= j)
            dp[i][j] = max(dp[i - 1][j], price[i - 1] + dp[i][j - i]);
        else
            dp[i][j] = dp[i - 1][j];

    return dp[n][n];
}

// note: sometimes prices wont be equal to length of rod, in that case dp will be n+1 * W+1 where W is total length of rod

