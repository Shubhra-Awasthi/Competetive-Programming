// 1) tle on n^3

vector<vector<int>> dp;

bool palindrome(string &s, int i, int j)
{
    while (i < j)
        if (s[i++] != s[j--])
            return false;
    return true;
}

int part(string &s, int i, int j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (palindrome(s, i, j))
        return dp[i][j] = 0;

    int mini = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int left = (dp[i][k] == -1) ? part(s, i, k) : dp[i][k];
        int right = (dp[k + 1][j] == -1) ? part(s, k + 1, j) : dp[k + 1][j];

        int temp = 1 + left + right;
        mini = min(mini, temp);
    }

    return dp[i][j] = mini;
}

int minCut(string s)
{
    int n = s.size();
    dp.resize(n + 1, vector<int>(n + 1, -1));

    return part(s, 0, s.size() - 1);
}

// 2) optimized O(n^2)

int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);

    for (int i = 0; i <= n; i++)
        dp[i] = n - i - 1; // worst case

    for (int i = n - 1; i >= 0; i--)
    {
        // Odd length palindromes
        for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++)
            dp[l] = min(dp[l], 1 + dp[r + 1]);

        // Even length palindromes
        for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++)
            dp[l] = min(dp[l], 1 + dp[r + 1]);
    }
    return dp[0];
}
