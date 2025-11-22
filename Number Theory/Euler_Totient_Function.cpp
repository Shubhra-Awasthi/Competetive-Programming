// No. of +ve int upto n, coprime to n: Euler Totient Function(ETF):

int phi(int n)
{
    int res = n;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            res /= i;
            res *= (i - 1);

            while (n % i == 0)
                n /= i;
        }

    if (n > 1)
        res /= n, res *= (n - 1);

    return res;
}
// O(sqrt(n))

// 2) ETF for 1 to n

void init(int maxN)
{
    for (int i = 1; i <= maxN; i++)
        phi[i] = i;

    for (int i = 2; i <= maxN; i++)
        if (phi[i] == i)
        {
            for (int j = i; j <= maxN; j += i)
            {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
}

// O(n log log n)