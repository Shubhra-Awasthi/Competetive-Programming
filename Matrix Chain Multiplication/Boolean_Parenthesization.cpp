// cnt number of ways to parenthesize the boolean expression such that the value of expression evaluates to true
string s;
vector<vector<vector<int>>> dp;

int countWays(string &s1)
{
    s = s1;

    int n = s.size();
    dp.resize(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));

    return solve(0, n - 1, true);
}

int solve(int i, int j, bool True)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (True)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    if (dp[i][j][True] != -1)
        return dp[i][j][True];

    int ans = 0;

    for (int k = i + 1; k < j; k += 2)
    {
        int LT = (dp[i][k - 1][1] != -1) ? dp[i][k - 1][1] : solve(i, k - 1, true);
        int LF = (dp[i][k - 1][0] != -1) ? dp[i][k - 1][0] : solve(i, k - 1, false);
        int RT = (dp[k + 1][j][1] != -1) ? dp[k + 1][j][1] : solve(k + 1, j, true);
        int RF = (dp[k + 1][j][0] != -1) ? dp[k + 1][j][0] : solve(k + 1, j, false);

        ans += evaluate(LT, LF, RT, RF, s[k], True);
    }

    return dp[i][j][True] = ans;
}

int evaluate(int LT, int LF, int RT, int RF, char c, bool True)
{
    if (c == '&')
    {
        if (True)
            return LT * RT;
        else
            return LT * RF + LF * RT + LF * RF;
    }
    else if (c == '|')
    {
        if (True)
            return LT * RT + LT * RF + LF * RT;
        else
            return LF * RF;
    }
    else
    { // '^'
        if (True)
            return LT * RF + LF * RT;
        else
            return LT * RT + LF * RF;
    }
}