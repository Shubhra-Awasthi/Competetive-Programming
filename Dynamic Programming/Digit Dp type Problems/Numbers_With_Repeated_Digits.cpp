class Solution
{
    int n;
    int dp[11][2][2][2][1 << 10];

    int solve(string &s, int idx, bool tight, bool rep, bool zero, int mask)
    {
        if (idx == n)
            return (rep && !zero);

        int &memo = dp[idx][tight][rep][zero][mask];
        if (memo != -1)
            return memo;

        int limit = tight ? s[idx] - '0' : 9;
        int res = 0;

        for (int dig = 0; dig <= limit; dig++)
        {
            bool nextTight = tight && (dig == limit);
            bool nextZero = zero && (dig == 0);

            if (nextZero)
                res += solve(s, idx + 1, nextTight, rep, true, mask); // dont mark 0
            else
            {
                bool nextRep = rep || ((mask >> dig) & 1);
                int nextMask = mask | (1 << dig);

                res += solve(s, idx + 1, nextTight, nextRep, false, nextMask);
            }
        }

        return memo = res;
    }

public:
    int numDupDigitsAtMostN(int num)
    {
        string s = to_string(num);
        n = s.size();

        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 1, 0, 1, 0);
    }
};

/*
idx = cur index
tight = restriction for digit picking or not
rep = repated digit in the number or not
zero = number is 0 or not
mask = bitmask for which digits are already set

you can solve reverse also for more efficient code: find unique elements till num and subtract from num + 1(not 0)
*/
