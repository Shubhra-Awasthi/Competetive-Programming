lli binexp(lli base, lli exp, lli modulus = 1e9 + 7)
{
    lli res = 1;
    base %= modulus;
    while (exp > 0)
    {
        if (exp % 2 == 1)
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