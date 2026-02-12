// Choose operation(nCr): Binomial Coefficient:

ll C(ll n, ll k)
{
    ll ans = 1;
    if (k > n - k)
        k = n - k;

    for (ll i = 1; i <= k; i++)
        ans *= (n - i + 1), ans /= i;

    return ans;
}