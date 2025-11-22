long long gcd(long long a, long long b)
{
    while (b)
    {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

long long lcm(long long a, long long b)
{
    if (a == 0 || b == 0)
        return 0;
    // Use (a / gcd(a, b)) * b to avoid potential overflow of a * b
    return (a / gcd(a, b)) * b;
}