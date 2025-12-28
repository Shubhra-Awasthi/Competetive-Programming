// https://leetcode.com/contest/weekly-contest-482/problems/number-of-balanced-integers-in-a-range/

#define ll long long

class Solution
{
    int n;
    ll dp[17][2][(10 * 15) << 1][2][2];

    ll solve(string &s, int idx, bool tight, int dif, bool zero, bool parity)
    {
        if (idx == n)
            return (zero && !dif);

        ll &memo = dp[idx][tight][dif + 140][zero][parity];
        if (memo != -1)
            return memo;

        int en = tight ? s[idx] - '0' : 9;
        ll res = 0;

        for (int d = 0; d <= en; d++)
        {
            bool tight1 = (tight && d == en);

            if (!zero)
            {
                if (!d)
                    res += solve(s, idx + 1, tight1, 0, 0, 0);
                else
                    res += solve(s, idx + 1, tight1, -d, 1, 1);
            }
            else
            {
                int dif1 = parity ? (dif + d) : (dif - d);
                res += solve(s, idx + 1, tight1, dif1, 1, !parity);
            }
        }

        return memo = res;
    }

public:
    long long countBalanced(long long low, long long high)
    {
        string s1 = to_string(low - 1);
        string s2 = to_string(high);

        while (s1.size() < s2.size())
            s1 = '0' + s1;

        memset(dp, -1, sizeof(dp));
        n = s2.size();
        ll hi = solve(s2, 0, 1, 0, 0, 0);

        memset(dp, -1, sizeof(dp));
        n = s1.size();
        ll lo = solve(s1, 0, 1, 0, 0, 0);

        return hi - lo;
    }
};