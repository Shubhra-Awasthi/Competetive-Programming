// Shortest Common Supersequence
int scs(string s1, string s2)
{
    return s1.size() + s2.size() - lcs(s1, s2);
}

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

// Printing SCS
vector<vector<int>> dp; // initialized globally

string printSCS(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    dp.resize(n + 1, vector<int>(m + 1, 0));

    lcs(s1, s2);
    string s = lcs_str(s1, s2);

    string res;
    int i = 0, j = 0;

    for (char c : s)
    {
        while (i < n && s1[i] != c)
            res += s1[i++];
        while (j < m && s2[j] != c)
            res += s2[j++];

        res += c;
        i++;
        j++;
    }

    res += s1.substr(i) + s2.substr(j);
    return res;
}

string lcs_str(string &s1, string &s2)
{
    int i = s1.size();
    int j = s2.size();

    string s;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            s += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(s.begin(), s.end());
    return s;
}