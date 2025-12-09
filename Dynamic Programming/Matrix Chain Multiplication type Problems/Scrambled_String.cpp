// https://www.interviewbit.com/problems/scramble-string/
vector<vector<vector<int>>> dp;
string a, b;

isScramble(const string A, const string B)
{
    a = A, b = B;

    int n = a.size();
    dp.assign(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

    return solve(0, 0, n);
}

int solve(int i, int j, int len)
{ // returns 0/1
    int &mem = dp[i][j][len];
    if (mem != -1)
        return mem;
    if (len == 1)
        return mem = (a[i] == b[j]) ? 1 : 0;

    // diff chars
    if (!sameCount(i, j, len))
        return mem = 0;

    for (int k = 1; k < len; ++k)
    {
        if (solve(i, j, k) && solve(i + k, j + k, len - k))
            return mem = 1; // no swap
        if (solve(i, j + len - k, k) && solve(i + k, j, len - k))
            return mem = 1; // swap
    }
    return mem = 0;
}

// slower by log n factor
bool sameCount(int i, int j, int len)
{
    multiset<char> s1(a.begin() + i, a.begin() + i + len);
    multiset<char> s2(b.begin() + j, b.begin() + j + len);

    return s1 == s2;
}

// optimal
//  bool sameCount(int i, int j, int len)
//  {
//      int cnt[26] = {0};
//      for (int t = 0; t < len; ++t)
//      {
//          ++cnt[a[i + t] - 'a'];
//          --cnt[b[j + t] - 'a'];
//      }
//      for (int x = 0; x < 26; ++x)
//          if (cnt[x] != 0)
//              return false;
//      return true;
//  }