int n, mod; // mod is prime
int fact[n], inv_fact[n];

void init()
{
    fact[0] = 1;
    int i;

    for (i = 1; i < n; i++)
        fact[i] = i * fact[i - 1] % mod;
    i--;

    inv_fact[i] = pw(fact[i], mod - 2, mod);
    for (i--; i >= 0; i--)
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
}

int ncr(int n, int r)
{
    if (r > n || n < 0 || r < 0)
        return 0; // ncr invalid
    return fact[n] * (inv_fact[r] % mod) * (inv_fact[n - r] % mod);
}

// O(n + log mod)