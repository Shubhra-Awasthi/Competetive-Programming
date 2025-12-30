ll binexp(ll base, ll exp, ll modulus = 1e9 + 7)
{
    ll res = 1;
    base %= modulus;
    while (exp > 0)
    {
        if (exp & 1)
        {
            res = ((__int128)res * base) % modulus;
        }
        base = ((__int128)base * base) % modulus;
        exp /= 2;
    }
    return res;
}

// Same as pow() but for floating point base and integer exponent
// O(log(exp))