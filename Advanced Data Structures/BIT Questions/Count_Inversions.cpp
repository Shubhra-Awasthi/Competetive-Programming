#include <bits/stdc++.h>
using namespace std;

struct BIT
{
    int n;
    vector<long long> bit;

    BIT(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, int val)
    {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    long long query(int i)
    {
        long long sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }
};

void compress(vector<int> &a)
{
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < a.size(); i++)
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
}

long long countInversions(vector<int> &a)
{
    int n = a.size();

    compress(a);

    BIT ft(temp.size());
    long long inv = 0;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        inv += ft.query(a[i] - 1); // count smaller elements
        ft.update(a[i], 1);        // inc freq of a[i]
    }

    return inv;
}
