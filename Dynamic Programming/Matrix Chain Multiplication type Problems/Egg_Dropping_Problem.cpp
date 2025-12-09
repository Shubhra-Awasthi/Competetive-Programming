// given e eggs and f floors, find minimum number of attempts needed in worst case to find the critical floor
vector<vector<int>> dp;

int superEggDrop(int e, int f)
{
    dp.assign(e + 1, vector<int>(f + 1, -1));
    return solve(e, f);
}

int solve(int e, int f)
{
    if (f <= 1 || e == 1)
        return f;
    if (dp[e][f] != -1)
        return dp[e][f];

    int mn = INT_MAX;
    int l = 1, h = f;
    while (l <= h)
    {
        int k = l + (h - l) / 2;

        if (dp[e - 1][k - 1] == -1)
            dp[e - 1][k - 1] = solve(e - 1, k - 1);
        if (dp[e][f - k] == -1)
            dp[e][f - k] = solve(e, f - k);

        int temp = 1 + max(dp[e - 1][k - 1], dp[e][f - k]);
        mn = min(mn, temp);

        if (dp[e - 1][k - 1] < dp[e][f - k])
            l = k + 1;
        else
            h = k - 1;
    }

    return dp[e][f] = mn;
}

// O(e * f log f) time complexity