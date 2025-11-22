for (int i = 1; i * i <= n; i++)
{
    if (n % i == 0)
    {
        Cnt++;
        if (i != n / i)
            cnt++;
    }
}

// O(√n)