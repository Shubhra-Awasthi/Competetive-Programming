vector<vector<int>> dp;

int MCM(vector<int> &arr)
{
    int N = arr.size();
    dp.resize(N, vector<int>(N, -1));

    return solve(arr, 1, N - 1);
}

int solve(vector<int> &arr, int i, int j)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int temp = solve(arr, i, k) +
                   solve(arr, k + 1, j) +
                   (arr[i - 1] * arr[k] * arr[j]);

        mini = min(mini, temp);
    }

    return dp[i][j] = mini;
}
