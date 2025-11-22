int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

// same as __gcd from <algorithm> header
// O(log(min(a, b)))