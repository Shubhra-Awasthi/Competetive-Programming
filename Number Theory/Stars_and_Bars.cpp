// Choose operation(nCr): Binomial Coefficient:

lli C(lli n, lli k)
{
    lli ans = 1;
    if (k > n - k)
        k = n - k;

    for (lli i = 1; i <= k; i++)
        ans *= (n - i + 1), ans /= i;

    return ans;
}