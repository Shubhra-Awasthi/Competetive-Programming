cin >> N;
int res = 0;

for (int i = 1; i * i <= n; i++)
{
    if (n % i == 0)
    {
        int d1 = i;
        int d2 = N / i;

        res += d1 * getCount(d1, N);

        if (d1 != d2)
            res += d2 * getCount(d2, N);
    }
}
// getCount = return phi[N / d]. Phi is Euler Totient Function.
// O(nlogn + sqrt(n))
