int n, m; // m is prime
int fact[n], inv_fact[n];

void init()
{
    fact[0] = 1;
    int i;

    for (i = 1; i < n; i++)
        fact[i] = i * fact[i - 1] % m;
    i--;

    inv_fact[i] = pw(fact[i], m - 2, m);
    for (i--; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % m;
}

int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0; // ncr invalid
    return fact[n] * (inv_fact[r] % m) * (inv_fact[n - r] % m);
}

// O(n + log m)