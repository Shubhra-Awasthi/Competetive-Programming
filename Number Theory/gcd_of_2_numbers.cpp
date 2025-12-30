int gcd(int a, int b)
{
    if (!a)
        return b;
    return gcd(b % a, a);
}

// same as __gcd from <algorithm> header
// O(log(min(a, b)))