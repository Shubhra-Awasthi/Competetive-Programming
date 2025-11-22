// 1) Fermat Primality Test (Probability Based): O(n log n)

bool probablyPrimeFermat(int n, int iter = 5)
{
    if (n < 4)
        return n == 2 || n == 3;

    for (int i = 0; i < iter; i++)
    {
        int a = 2 + rand() % (n - 3);
        if (binpower(a, n - 1, n) != 1)
            return false;
    }
    return true;
}

// 2) Miller-Rabin Primality Test (Deterministic for small bases): O(log n)^3

bool MillerRabin(u64 n)
{ // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0)
    {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

bool check_composite(u64 n, u64 a, u64 d, int s)
{
    u64 x = modpow(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++)
    {
        x = modmul(x, x, n);
        if (x == n - 1)
            return false;
    }
    return true;
}