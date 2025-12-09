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

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
        if (s[i++] != s[j--])
            return false;
    return true;
}

int minCut(string s)
{
    int n = s.size();

    // dp[i] = minimum cuts needed from index i to end
    vector<int> dp(n + 1, 0);

    dp[n] = 0; // empty substring → zero cuts

    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;

        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + dp[j + 1]; // cut + cost
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }

    // -1 for cut count not partitions
    return dp[0] - 1;
}
