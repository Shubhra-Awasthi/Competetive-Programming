const int MAXN = 1e7 + 1;
vector<int> spf(MAXN); // spf[i] stores smallest prime factor of i

// Preprocessing: O(n log log n)
void sieve()
{
    for (int i = 2; i < MAXN; i++)
    {
        if (spf[i] == 0)
        {
            for (int j = i; j < MAXN; j += i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
}

// Factorization: O(log n)
vector<int> getPrimeFactors(int n)
{
    vector<int> factors;
    while (n > 1)
    {
        int p = spf[n];
        while (n % p == 0)
        {
            factors.push_back(p);
            n /= p;
        }
    }
    return factors;
}