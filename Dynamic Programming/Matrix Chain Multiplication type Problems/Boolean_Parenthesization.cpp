// cnt number of ways to parenthesize the boolean expression such that the value of expression evaluates to true
string s;
vector<vector<vector<int>>> dp;

int evaluate(int LT, int LF, int RT, int RF, char c, bool True)
{
    if (c == '&')
        return True ? LT * RT : LT * RF + LF * RT + LF * RF;
    if (c == '|')
        return True ? LT * RT + LT * RF + LF * RT : LF * RF;
    return True ? LT * RF + LF * RT : LT * RT + LF * RF; // '^'
}

int solve(int i, int j, bool True)
{
    if (i > j)
        return 0;
    if (i == j)
        return True ? s[i] == 'T' : s[i] == 'F';

    int &ans = dp[i][j][True];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int LT = solve(i, k - 1, 1);
        int LF = solve(i, k - 1, 0);
        int RT = solve(k + 1, j, 1);
        int RF = solve(k + 1, j, 0);

        ans += evaluate(LT, LF, RT, RF, s[k], True);
    }
    return ans;
}

int countWays(string &s1)
{
    s = s1;
    int n = s.size();
    dp.assign(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return solve(0, n - 1, 1);
}
