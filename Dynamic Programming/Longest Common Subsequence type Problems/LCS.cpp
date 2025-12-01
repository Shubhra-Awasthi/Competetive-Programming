// Longest Common Subsequence

// 1) Recursion + Memoization
vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // initialize on constraints

int lcs(string &s1, string &s2, int n, int m)
{
    if (!n || !m)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
        return dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1);
    else
        return dp[n][m] = max(lcs(s1, s2, n - 1, m), lcs(s1, s2, n, m - 1));
}

// 2) Tabulation top down
int lcs(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    return dp[n][m];
}

// 3) Printing LCS
string printLCS(string s1, string s2)
{
    lcs(s1, s2); // Fill the dp table using the above lcs function

    // Now, reconstruct the LCS from the dp table
    int i = n, j = m;
    string lcs_str;

    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs_str.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(lcs_str.begin(), lcs_str.end());
    return lcs_str;
}