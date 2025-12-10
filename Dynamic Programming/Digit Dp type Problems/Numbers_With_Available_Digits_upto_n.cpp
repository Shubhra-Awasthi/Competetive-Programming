// https://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/

using ll = long long;

class Solution
{
    ll dp[11][2][2];
    int n;
    unordered_set<int> available;

    int solve(string &s, int idx, int tight, int zero)
    {
        if (idx == n)
            return !zero;
        if (dp[idx][tight][zero] != -1)
            return dp[idx][tight][zero];

        int st = 0;
        int en = tight ? s[idx] - '0' : 9;
        ll res = 0;

        for (int i = st; i <= en; i++)
        {
            if (!(zero && i == 0) && !available.count(i))
                continue;

            res += solve(s, idx + 1, (tight && (i == en)), (zero && i == 0));
        }

        return dp[idx][tight][zero] = res;
    }

public:
    int atMostNGivenDigitSet(vector<string> &digits, int num)
    {
        memset(dp, -1, sizeof(dp));

        for (auto s : digits)
            available.insert(stoi(s));

        string s = to_string(num);
        n = s.size();

        return solve(s, 0, 1, 1);
    }
};